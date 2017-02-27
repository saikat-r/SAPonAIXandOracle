static char sccsid[] = "@(#) $Id: //bas/640_REL/src/krn/rfc/rfcpumpd.cpp#1 $ SAP";
/*src----------------------------------------------------------------*
 * rfcpumpd.cpp  -- SAP RFC: Sample Windows Pump With Progress Dialog
 *
 *-------------------------------------------------------------------*
 *  SAP AG Walldorf
 *  Systeme, Anwendungen und Produkte in der Datenverarbeitung
 *
 *  (C) Copyright SAP AG 1998
 *-------------------------------------------------------------------*
 *
 *  A simple Windows pump for use in RFC programs.
 *  The code is provided as is.
 *  Modify this code to suite your requirements.
 *
 *end-----------------------------------------------------------------*/
#ifndef DONT_USE_STRICT
#   define STRICT 1     //needed with MFC projects
#endif
#define VC_EXTRALEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#ifndef _INC_COMMCTRL
#   include <commctrl.h>
#endif
#include <limits.h>
#include "saprfc.h"
#include "rfcpump.h"

/////////////////////////////////////////////////////////////////////////////
// cancel dialog window proc

BOOL CALLBACK RfcPumpDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM /*lParam*/)
{
    HWND hwnd;
    switch(message)
    {
    case WM_INITDIALOG:
        //SetWindowText(hDlg,...);

        ::EnableMenuItem(GetSystemMenu(hDlg, FALSE), SC_CLOSE, MF_GRAYED);

        hwnd = GetDlgItem(hDlg, IDCANCEL);
        if (NULL != hwnd)
        {
            ::ShowWindow(hwnd, SW_HIDE);
            ::EnableWindow(hwnd, FALSE);
        }
        return TRUE;

    case WM_COMMAND:
        if (IDCANCEL == wParam)
        {
            CRfcPump* p = (CRfcPump*)GetWindowLong(hDlg, DWL_USER);
            if (NULL != p)
                p->SetAbort(TRUE);
            ::EnableWindow(::GetParent(hDlg), TRUE);
            ::DestroyWindow(hDlg);
            p->SetClosed(); //close pump
        }
        return TRUE;
    }
    return FALSE;
}

//@doc-----------------------------------------------------------------
/*---------------------------------------------------------------------
 * @mfunc  | CRfcPump | CRfcPump | Construct with progress/cancel dialog
 *
 * This construct a <c CRfcPump> instance.
 *
 * If <p dm> has the value <e RFCP_DIALOG_MODE.RFCPDM_IMEDIATE>
 * the dialog is created immediately.
 * If it has the value  <e RFCP_DIALOG_MODE.RFCPDM_DELAYED>
 * the dialog is created only if needed.
 *
 * <p hInst> should be the instance from the module from
 * which the dialog template should be loaded.
 * <p DlgID> is the Id of the dialog template.
 * the CANCEL button (if any should have the ID IDCANCEL.
 *
 * <p hWndParent> should be the handle from the parent Windows.
 * It is generaly the main Windows from the application.
 *
 * If <p idProgress> is NULL, no progress indicator message
 * are sent.  Changing the values of <p uiRange> and <p uiStep>
 * change the speed at which the progress indicator is updated
 *
 * @xref <f CRfcPump>
 */
CRfcPump::CRfcPump(RFCP_DIALOG_MODE dm,   //@parm immediate/differed 
                                          // dialog creation
         HINSTANCE hInst,       //@parm module instance 
         UINT DlgID,            //@parm dialog template id
         HWND hWndParent,       //@parm parent Windows
         UINT idProgress,       //@parm progress indicator ID 
         UINT uiRange,          //@parm progress indicator range
         UINT uiStep            //@parm progress indicator step
        )
    : m_bUserAbort(FALSE),                                      
      m_hWndParent(hWndParent),
      m_hWndDlg(0),
      m_hWndDlgG(0),
      m_hWndProgress(0),
      m_State(RFCP_INIT),
      m_hInst(hInst),
      m_DlgID(DlgID),
      m_idProgress(idProgress),
      m_uiRange(uiRange),
      m_uiStep(uiStep)
{
    if (RFCPDM_IMEDIATE == dm)
        CreateCancelDialog(hInst, DlgID, hWndParent, idProgress, uiRange, uiStep) ;
    else
    {
        if (0 == hWndParent)
            hWndParent = ::GetActiveWindow();
        m_hWndParent = hWndParent;
        if (0 != m_hWndParent && ::GetDesktopWindow() != m_hWndParent)
            EnableWindow(m_hWndParent, FALSE);
    }
}


/*---------------------------------------------------------------------
 * @mfunc HWND | CRfcPump | CreateCancelDialog | Delayed dialog creation.
 *
 * This method is called internally, and may be called
 * externally if the <c CRfcPump> instance has been
 * created with the default constructor.
 *
 * <p hInst> should be the instance from the module from
 * which the dialog template should be loaded.
 * <p DlgID> is the Id of the dialog template.
 * the CANCEL button (if any should have the ID IDCANCEL.
 *
 * <p hWndParent> should be the handle from the parent Windows.
 * It is generaly the main Windows from the application.
 *
 * If <p idProgress> is NULL, no progress indicator message
 * are sent.  Changing the values of <p uiRange> and <p uiStep>
 * change the speed at which the progress indicator is updated
 *
 * @xref <f CRfcPump>
 */
HWND CRfcPump::CreateCancelDialog(HINSTANCE hInst, //@parm module instance        
                                UINT DlgID,        //@parm dialog template ID      
                                HWND hWndParent,   //@parm parent Windows          
                                UINT idProgress,   //@parm progress indicator ID   
                                UINT uiRange,      //@parm progress indicator range
                                UINT uiStep        //@parm progress indicator step 
                                )
{
    if (0 == hWndParent)
        hWndParent = ::GetActiveWindow();
    m_hWndParent = hWndParent;
    if (0 != m_hWndParent && ::GetDesktopWindow() != m_hWndParent)
        EnableWindow(m_hWndParent, FALSE);

    m_hWndDlgG =  m_hWndDlg = ::CreateDialog(hInst,
                                        MAKEINTRESOURCE(DlgID),
                                        m_hWndParent,
                                        RfcPumpDlgProc); 
    if (0 != m_hWndDlg)
    {
        SetWindowLong(m_hWndDlg, DWL_USER, (LONG)this);
        m_State = RFCP_CREATED;
        if (NULL != idProgress)
        {
            m_hWndProgress = GetDlgItem(m_hWndDlg, idProgress) ;
            if (NULL != m_hWndProgress)
            {
                ::SetFocus(m_hWndProgress);
                ::SendMessage(m_hWndProgress, PBM_SETRANGE, 0, MAKELPARAM(0, uiRange)); 
                ::SendMessage(m_hWndProgress, PBM_SETSTEP, uiStep, 0L);
            }
        }
    }
    else 
        m_State = RFCP_ERROR;
    return m_hWndDlg;
}//CRfcPump::CreateCancelDialog

/*---------------------------------------------------------------------
 * @mfunc HWND | CRfcPump | Pump | The inner Windows message pump
 *
 * This method is called internally by <mf CRfcPump.RfcPump>
 * and can be called externally by users which want to control
 * exactly when the Windows message pump is wound.
 * 
 * On each call, the progress bar is step <md .m_uiStep> steps
 * if a progress indicator exist on the dialog.
 * 
 * Change this method if you want to change the progress
 * indicator handling
 *
 * @xref <f CRfcPump>
 * 
 * @rdesc Continue
 * @flag TRUE | abort not requested
 * @flag FALSE| abort requested
 */
BOOL CRfcPump::Pump()
{
    if (   (RFCP_VISIBLE == m_State || RFCP_CANCEL == m_State)
        && m_hWndDlgG && m_hWndProgress && !m_bUserAbort)
        ::SendMessage(m_hWndProgress, PBM_STEPIT, 0, 0L);

    MSG msg;
    while (!m_bUserAbort && ::PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
    {
	if (!m_hWndDlgG || !IsDialogMessage(m_hWndDlgG, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return !m_bUserAbort;
}//CRfcPump::Pump()

/*---------------------------------------------------------------------
 * Show the dialog which is initialy hidden
 */
void CRfcPump::Show(BOOL b)
{
    if (!m_bUserAbort && m_hWndDlgG)
    {   
        ::ShowWindow(m_hWndDlgG, (b ? SW_SHOW: SW_HIDE));
        if (TRUE == b)
        {
            m_State = RFCP_VISIBLE;
        }
        else
        {
            m_State = RFCP_CREATED;
            ::ShowWindow(GetDlgItem(m_hWndDlgG, IDCANCEL), SW_HIDE);
            ::EnableWindow(GetDlgItem(m_hWndDlgG, IDCANCEL), FALSE);
        }
    }
}//CRfcPump::Show

/*---------------------------------------------------------------------
 * Enable the cancel button which is initialy hidden
 */
void CRfcPump::EnableCancel(void) 
{
    if (!m_bUserAbort && m_hWndDlgG)
    {
        if (RFCP_VISIBLE != m_State)
            Show(TRUE);
        if (m_hWndProgress)
            ::SendMessage(m_hWndProgress, PBM_SETPOS, 0, 0L);
        ::ShowWindow(GetDlgItem(m_hWndDlgG, IDCANCEL), SW_SHOW);
        ::EnableWindow(GetDlgItem(m_hWndDlgG, IDCANCEL), TRUE);
        m_State = RFCP_CANCEL;
    }
}//CRfcPump::EnableCancel

/*---------------------------------------------------------------------
 * mfunc HWND | CRfcPump | RfcPump | The RFC Windows message pump
 *
 * Call <mf .RfcPump> between <f RfcCall> and <f RfcReceive> 
 * or before <f RfcDispatch> or <f RfcGetName>. 
 *
 * rdesc Continue or abort
 * flag if <gt>= 0 | RFC_RC as returned from <f RfcListen>
 * flag if <lt> 0  | Abort has been requested
 */
int CRfcPump::RfcPump(RFC_HANDLE hRfc)
{
    RFC_RC rfc_rc;
    BOOL   bContinue = TRUE;

    for ( ;
             RFC_RETRY == (rfc_rc = RfcListen(hRfc))
          && TRUE == (bContinue = Pump())
          ;
        ) {;}//NOP
    
    if (0 == bContinue)
        return -1;
    return rfc_rc;
}


#define TICK_SPAN( dwS, dwE) \
        ((dwE >= dwS) ? (dwE - dwS) : ((ULONG_MAX - dwS) + dwE))
/*---------------------------------------------------------------------
 * @mfunc HWND | CRfcPump | RfcPump | The RFC Windows message pump
 *
 * Call <mf .RfcPump> between <f RfcCall> and <f RfcReceive> 
 * or before <f RfcDispatch> or <f RfcGetName>. 
 *
 * - Calls <mf .Pump> internally<nl>
 * - Shows the dialog after <p dwHidden> milliseconds,<nl>
 * - Enable the cancel button after <p dwCancel> milliseconds<nl>
 * - Returns users'cancel request or RFC state.
 * 
 * Assume that the dialog has been created or cached! 
 * (by constructor or by <mf .CreateCancelDialog>)
 *
 * Exist also as an overloaded member without dialog. 
 * I.e. AbortProc only.
 *
 * @xref <f CRfcPump>
 *
 * @rdesc Continue or abort
 * @flag if <gt>= 0 | RFC_RC as returned from <f RfcListen>
 * @flag if <lt> 0  | Abort has been requested
 */
int CRfcPump::RfcPump(RFC_HANDLE hRfc, //@parm module instance        
                      DWORD dwHidden,  //@parm msTime before Progress 
                                       // Dialog is shown
                      DWORD dwCancel)  //@parm ms, Time before Cancel 
                                       // Button is enabled
{
    RFC_RC rfc_rc;
    BOOL   bContinue = TRUE;
    DWORD  dwStart   = GetTickCount();

    while (  RFC_RETRY == (rfc_rc = RfcListen(hRfc))
          && TRUE == (bContinue = Pump())
          ) 
    {
        RFCP_PUMPSTATE  s = GetState(); 
        if (RFCP_CANCEL != s)
        {
            DWORD dwEnd  = GetTickCount();
            DWORD dwSpan = TICK_SPAN(dwStart, dwEnd);
            if (dwSpan > dwHidden)
            {
                if (RFCP_INIT == s)
                {
                    CreateCancelDialog(m_hInst,
                        m_DlgID,
                        m_hWndParent,
                        m_idProgress,
                        m_uiRange,
                        m_uiStep) ;
                    Show(TRUE);
                }
                else if (RFCP_CREATED == s)
                    Show(TRUE);
            }
            if (RFCP_VISIBLE == GetState() && dwSpan >  dwCancel)
                EnableCancel();
        }
    }
    if (0 == bContinue)
        return -1;
    return rfc_rc;
}
