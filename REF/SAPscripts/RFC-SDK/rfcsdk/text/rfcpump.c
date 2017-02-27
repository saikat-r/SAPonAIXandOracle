static char sccsid[] = "@(#) $Id: //bas/640_REL/src/krn/rfc/rfcpump.c#1 $ SAP";
/*src----------------------------------------------------------------*
 * rfcpump.c  -- SAP RFC: sample simple Windows pump
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
#include "saprfc.h"
#include "rfcpump.h"


int RfcPump( HWND       hWndMain, /* @parm Main Windows */
             RFC_HANDLE handle,   /* @parm the RFC connection performing
                                   *        the long lasting call
                                   */
             int       *piAbort   /* @parm Abort if *piAbort <> 0 */
           )
{
    MSG    msg;
    RFC_RC rfc_rc = RFC_OK;
    int    foo = 0;

    if (0 != hWndMain)
        EnableWindow(hWndMain, FALSE);
    if (NULL == piAbort)
        piAbort = &foo;

    while (  !*piAbort && RFC_RETRY == (rfc_rc = RfcListen(handle)))
    {
        while (!*piAbort && PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    if (0 != hWndMain)
        EnableWindow(hWndMain, TRUE);

    if (*piAbort)
        return -1;
    return rfc_rc;
}
