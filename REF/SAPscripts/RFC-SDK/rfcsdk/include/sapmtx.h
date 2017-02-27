/* @(#) $Id: //bas/640_REL/src/include/sapmtx.h#4 $ SAP*/
/*-----------------------------------------------------------------------------
 * R F C  S D K
 *
 * DCOM Connector
 * Microsoft Transaction Server Interface
 *
 * (c) Copyright SAP AG, Walldorf  1997
 *-----------------------------------------------------------------------------
 */
/*SAPUNICODEOK_FILE*/
/*
 * @doc
 *
 * @module DCOM Connector  |
 *
 * Classes for managing RFCs, BAPIs and Distributed ABAP objects 
 * within Microsoft Transaction Server:
 *
 * @flag <f CSapConnector> |
 *  template class to be used as base class for ATL proxies. 
 * 
 * @flag <f CAbapType> |
 *  template class to hold an ABAP type description.
 *
 * @flag <f CAbapScalarType> |
 *  class to hold an ABAP type description for a primitive scalar type.
 *
 * @flag <f CAbapTable> |
 *  class to work with ABAP internal tables including the mapping to
 * ADO and RDS Recordsets and OLEDB Rowsets.
 *
 * 
 */

#ifndef __midl
#ifndef SAPTYPE_H
#ifndef SAPonNT
// only on Windows NT or Windows 95
#define SAPonNT
#endif  /* SAPonNT */
//#include "saptype.h"
#include <stdio.h>
#include <time.h>
#define SAPwithTHREADS
#endif  /* SAPTYPE_H */
#include <mtx.h>
#ifndef SAPRFC_H
#include "saprfc.h"
#endif  /* SAPRFC_H */
#ifndef SAPOBJ_H
#include "sapobj.h"
#endif  /* SAPOBJ_H */
#ifndef __sapirfc_h__
#include "sapirfc.h"
#endif
#endif /* __midl */

#ifndef SAPMTX_H
#define SAPMTX_H

#ifdef __midl
#ifndef SAP_API
#define SAP_API
#endif  /* SAP_API */
#endif /* __midl */

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * end of C part
 */
#ifdef __cplusplus
}
#endif /* C++ */

#ifdef __cplusplus

#ifndef RFC_RELEASE_INTERFACE
#define RFC_RELEASE_INTERFACE( punk ) \
( ( NULL == punk ) ? 0 : (punk->Release(), punk = NULL ) )
#endif

#ifndef __midl
/* do not bother MIDL with template classes */

/* printf for OLECHAR*....
 * _stprintf(tcBuff, _T("This is my BSTR:>%") RFC_PRINTF_OLES _T("<\n"), bsrValue);
 */
#ifndef RFC_PRINTF_OLES 
#	ifdef SAPwithUNICODE
#		define  RFC_PRINTF_OLES _T("s")
#		define  RFC_PRINTF_OLEC _T("c")
#		define  RFC_PRINTF_MBCS _T("S")
#	else
#		define  RFC_PRINTF_OLES _T("S")
#		define  RFC_PRINTF_OLEC _T("C")
#		define  RFC_PRINTF_MBCS _T("s")
#	endif
#endif
class CRfcResourceDispenser
{
private:
    static ISAPrfcContextSource * m_pISAPrfcContextSource;
    static HRESULT GetFirstContextSource( ISAPrfcContextSource ** ppISAPrfcContextSource );
public:
    static HRESULT GetContextSource( ISAPrfcContextSource ** ppISAPrfcContextSource );
    static HRESULT OnError( _TCHAR * entryPoint, _TCHAR * fname, int line, _TCHAR * text, HRESULT hr );
    static void    Trace( _TCHAR * entryPoint, _TCHAR * fname, int line, _TCHAR * text, HRESULT hr = S_OK );
	static void    ErrorReset();
    static void    _CleanUpForLeakTest();
    static CComAutoCriticalSection m_cs;
};

// @class Class for effectively handling HRESULT return codes.
// 
// The class overloads the |-operator, such you can handle   
// HRESULT values indicating failure very shortly.  
// 
// @ex the following example shows the usage of CSapController
//     within a method call build by using <c CSapBaseProxy>. |
//
// class CTest : CSapBaseProxy< CTest, CLSID_CTest >
// ...
//
// HRESULT CTest::Test( /*[in]*/ BSTR string )
// {
//     CSapController controller;
//
//     try
//     {
//        CallFunction( L"TEST" )             >> controller;
//           Exporting( "STRING", string )    >> controller;
//     }
//     catch( HRESULT hr )
//     {
//        return hr;
//     }
//
//     return S_OK;
// }
extern _TCHAR g_szSAPMTX_H[] ; // for use with CSapController( _TCHAR * fname) ;
class CSapController
{
public:
    CSapController() : m_hResult( S_OK ), 
                       m_status( _T("") ),
                       m_file( _T("?") ),
                       m_line( 0 ),
                       m_entryPoint( _T("CSapContoller") )
    {}

    CSapController( _TCHAR * fname) : 
                                    m_hResult( S_OK ), 
                                    m_status( _T("") ), 
                                    m_file( fname ),
                                    m_line( 0 ),
                                    m_entryPoint( _T("") )
    {
       if( m_file != NULL && m_file[0] == _T('@') )
       {
          m_file += 4;
       }
    }

    ~CSapController()
    {}

    // @cmember define COM entry point
    void EntryPoint( _TCHAR * entryPoint )
    {
        m_entryPoint = entryPoint;
        CRfcResourceDispenser::ErrorReset();
        CRfcResourceDispenser::Trace( entryPoint, m_file, 0, _T("ENTRY POINT") );
        return;
    }

    // @cmember returns the last HRESULT value or S_OK.
    HRESULT Result()
    {
        return m_hResult;
    }

    // @cmember define COM exit point
    HRESULT Return( HRESULT hr )
    {
        CRfcResourceDispenser::Trace( m_entryPoint, m_file, 0, _T("EXIT"), hr );
        return hr;
    }

    // @cmember initialize HRESULT value to S_OK.
    void InitController()
    {
        m_hResult = S_OK;
    }

    // @cmember sets trace information
    CSapController& Info( int line, _TCHAR * operation )
    {
        m_line   = line;
        m_status = operation;

#ifdef SAPMTX_TRACE_ON
        CRfcResourceDispenser::Trace( m_entryPoint,
	                              m_file,
				      line,
				      operation );
#endif
        return *this;
    }

    CSapController& Line( int line)
    {
        m_line   = line;
        return *this;
    }

    // @cmember overloaded 'Pipe'-operator. Throws HRESULT on error.
    friend HRESULT operator>> ( HRESULT hr, CSapController& controller );

private:
    HRESULT m_hResult;
    _TCHAR *  m_status;
    _TCHAR *  m_file;
    int     m_line;
    _TCHAR *  m_entryPoint;
};

#define INFO( t )  Info( __LINE__, t )
#define XLine(x)   x.Line( __LINE__)

inline HRESULT operator>> (  HRESULT hr,  
                             CSapController& controller )
{
    controller.m_hResult = hr;

    if( FAILED( hr ) )
    {
        CRfcResourceDispenser::OnError( controller.m_entryPoint,
                                        controller.m_file, 
                                        controller.m_line, 
                                        controller.m_status, 
                                        hr );

        throw hr;
    }
    else
    {
#ifdef SAPMTX_TRACE_ON
        CRfcResourceDispenser::Trace(   controller.m_entryPoint,
                                        controller.m_file, 
                                        controller.m_line, 
                                        controller.m_status
                                    );
#endif
    }

    controller.m_status = _T("");
    return hr;
}

template <class T> class CAbapType; 

// @class Class describing a scalar ABAP data type.
//
class CAbapScalarType
{
public:
    // @cmember Creates a new scalar data type (<t RFCTYPE>).
    // Optional parameters are the length of the field and the decimals.
    // Length must be given for TYPE C, TYPE N, TYPE P and TYEP X fields.
    // Decimals can only be set for TYPE P fields.
    CAbapScalarType( RFCTYPE rfctype, unsigned bytes = 0, unsigned decimals = 0 );


    RfcInvokeScalarType * getType()
    {
        return &m_ScalarType;
    }

private:
    RfcInvokeScalarType m_ScalarType;

};

struct CSapSchemaObject;
struct CSapSchemaVerb;
class CSapRegistryHelper;

template <class T >
class CSapCatalogImpl : public ISAPCatalog
{
public:
    STDMETHOD(GetTypeInfoCount)(unsigned int *c){return E_NOTIMPL;}
    STDMETHOD(GetTypeInfo)(unsigned int i,unsigned long l ,struct ITypeInfo ** t){return E_NOTIMPL;}
    STDMETHOD(GetIDsOfNames)(REFIID  riid,  OLECHAR ** rgszNames, unsigned int  cNames, LCID   lcid, DISPID * rgDispId  ){ return E_NOTIMPL;}
    STDMETHOD(Invoke)(long l, const struct _GUID &g, unsigned long ul, unsigned short us, struct tagDISPPARAMS *p, struct tagVARIANT *v, struct tagEXCEPINFO *x, unsigned int *pi) {return E_NOTIMPL;}
    STDMETHOD(GetSchemata)( 
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr;
        hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetSchemata(ppTab);
        return hr;
    }
    
    STDMETHOD(GetClasses)( 
        /* [in] */ BSTR schemaName,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetClasses(schemaName, ppTab);
        return hr;
    }
    
    STDMETHOD(GetMethods)( 
        /* [in] */ BSTR schemaName,
        /* [in] */ BSTR className,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetMethods(schemaName, className, ppTab);
        return hr;
    }
    
    STDMETHOD(GetProperties)( 
        /* [in] */ BSTR schemaName,
        /* [in] */ BSTR className,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr;
        hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetProperties(schemaName, className, ppTab);
        return hr;
    }
    
    STDMETHOD(GetTypes)( 
        /* [in] */ BSTR schemaName,
        /* [in] */ BSTR className,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr;
        hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetTypes(schemaName, className, ppTab);
        return hr;
    }
    
    STDMETHOD(GetMethodParameters)( 
        /* [in] */ BSTR schemaName,
        /* [in] */ BSTR className,
        /* [in] */ BSTR methodName,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr;
        hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetMethodParameters(schemaName, className, methodName, ppTab);
        return hr;
    }
    
    STDMETHOD(GetTypeColumns)( 
        /* [in] */ BSTR schemaName,
        /* [in] */ BSTR className,
        /* [in] */ BSTR typeName,
        /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppTab)
    {
        HRESULT hr;
        hr = Init();
        if (SUCCEEDED(hr))
            hr = m_CatalogHelper->GetTypeColumns(schemaName, className, typeName, ppTab);
        return hr;
    }

public:
    virtual HRESULT CSapCatalogImpl_GetSchema( CSapSchemaObject ** pObjSchema, CSapSchemaVerb ** pverbSchema ) 
    { 
        return E_FAIL; 
    }
    
private:
    HRESULT Init(void)
    {
        m_cs.Lock();
        if( NULL == m_CatalogHelper.p )
        {
            //CAnyAbapType * pAllTypes[1024];
            HRESULT hr;

            CSapSchemaObject * pObjSchema;
            CSapSchemaVerb   * pverbSchema;
            hr = this->CSapCatalogImpl_GetSchema( &pObjSchema, &pverbSchema );
            if( FAILED( hr ) )
            {
                hr = AtlReportError( CLSID_RfcSchemaSource, 
                                     _T("No meta data available for class."), 
                                     IID_ISAPCatalog, 
                                     hr );
                m_cs.Unlock();
                return hr;
            }
            hr = CoCreateInstance(CLSID_RfcSchemaSource, 
		                  0,
		                  CLSCTX_INPROC_SERVER,
#ifdef SAPwithUNICODE
						  IID_ISAPCatalog4CU,	
#else
		                  IID_ISAPCatalog4C,
#endif
		                  (void **) &m_CatalogHelper);
            if( FAILED( hr ) )
            {
                hr = AtlReportError( CLSID_RfcSchemaSource, 
                                     _T("Cannot create catalog helper."), 
#ifdef SAPwithUNICODE
									 IID_ISAPCatalog4CU, 
#else
                                     IID_ISAPCatalog4C, 
#endif
                                     hr );
                m_cs.Unlock();
                return hr;
            }
            hr = m_CatalogHelper->CreateFromData( 
                                        ( NULL == pObjSchema->sapsystem ? 
                                          L"CONNECTOR" : pObjSchema->sapsystem),
                                        sizeof(CSapSchemaObject),
                                        (BYTE*)pObjSchema,
                                        sizeof(CSapSchemaVerb),
                                        (BYTE*)pverbSchema);
            if( FAILED( hr ) )
            {
                m_cs.Unlock();
                return hr;
            }
            int allTypeEntries = 0;
            for( int i = 0; SAP_ID_SCHEMA_END != pverbSchema[i].Type; i++ )
            {
				USES_CONVERSION;
                switch( pverbSchema[i].Type )
                {
                case SAP_ID_SCHEMA_PARAMETER:   // Parameter
                case SAP_ID_SCHEMA_KEY:   // Key
                case SAP_ID_SCHEMA_ATTRIBUTE:   // Attribute
                    if( NULL != pverbSchema[i].AbapType )
                    {
                        CAnyAbapType * pType = pverbSchema[i].AbapType;

						 unsigned char * typeName = (unsigned char *) pType->getTypeName();
						 const RFC_TYPE_ELEMENT * pElements  = NULL;
						 unsigned int       elementCnt = 0;
						 pType->getTypeDescription( &pElements, &elementCnt );
						 hr = m_CatalogHelper->InitializeType( 
#ifdef SAPwithUNICODE
	 														   A2T((char*)typeName),
															   W2CT(pverbSchema[i].RefStruct),
															   A2T((char*)typeName),
															   sizeof( RFC_TYPE_ELEMENT),
															   (unsigned char *) pElements,
															   (unsigned long) elementCnt );
#else
															   typeName,
															   (const unsigned char *)W2CA(pverbSchema[i].RefStruct),
															   typeName,
															   sizeof( RFC_TYPE_ELEMENT),
															   (unsigned char *) pElements,
															   (unsigned long) elementCnt );
#endif
						 if( FAILED( hr ) )
						 {
							m_cs.Unlock();
							return hr;
						 }
                         //pAllTypes[allTypeEntries++] = pType;
                    }
                    break;
                }
            }
        }
        m_cs.Unlock();
        return S_OK;
    }
#ifdef SAPwithUNICODE
    CComPtr<ISAPCatalog4CU> m_CatalogHelper; 
#else
	CComPtr<ISAPCatalog4C>  m_CatalogHelper; 
#endif
    CComAutoCriticalSection m_cs;
};

// @class Template class for MTS proxy objects of ABAP objects
// 
// @tcarg class | T | The derived class acting as a proxy
// @tcarg const CLSID * | pclsid | pointer to Class ID of the proxy
// 
//
// CSapBaseProxy offers several methods for easily calling R/3
// functions. These methods handle all the connection management and
// the complete error handling internally. On errors they set IErrorInfo
// and throw a exception of type HRESULT.
// Also these methods handle all necessary conversions between OLE and 
// ABAP data types.
//
//

enum RFC_CALL_TYPE
{
	SYNC_RFC = 0,
	T_RFC    = 1,
	Q_RFC    = 2
};

template <class T, const CLSID* pclsid, const RFC_CALL_TYPE uRfcType = SYNC_RFC>
class CSapBaseProxy : public CComObjectRootEx< CComSingleThreadModel >,
                      public CComCoClass< T, pclsid >,
					  public ISAPrfcBind,	
                      //public IDispatchImpl< ISAPrfcBind, &IID_ISAPrfcBind, &LIBID_IRFC32Lib > ,
                      public CSapCatalogImpl< T >,
                      public ISupportErrorInfo
{
public:
    CSapBaseProxy()
    {
		m_uRfcType = uRfcType;
 		m_Destination = _T("");
		m_Bound = 0;
		m_Cookie = 0;
		m_RfcSession.Release();
		m_KeepSAPContext = TRUE;
		m_TID = _T("");
		m_QName = _T("");
		m_QCount = 0;
    }
   
    virtual ~CSapBaseProxy() 
    {
    }
	
	void FinalRelease()
	{
		if(FALSE == !m_RfcSession)
			m_RfcSession->ClearInvalidRef(m_Cookie);
        Reset();
	}

private:
protected:
    virtual void Reset()
    {
		ReleaseRfcContext();
		m_Destination = _T("");
    }

public:
    STDMETHOD( InterfaceSupportsErrorInfo )( REFIID riid )
    {
        // support error info for all interfaces
        return S_OK;
    }

protected:
    static CSapRegistryHelper * SapConnectorGetNewHelper(CSapSchemaObject * pObjSchema)
    {
        CSapRegistryHelper * pHelper = new CSapRegistryHelper( pclsid, NULL, NULL, pObjSchema );
        return pHelper;
    }


public:
    static CSapSchemaObject * getObjSchema() { return NULL; }

    virtual HRESULT GetSchema( CSapSchemaObject ** ppObjSchema, CSapSchemaVerb ** ppverbSchema ) 
    { 
        return E_FAIL; 
    }

public:
    virtual HRESULT CSapCatalogImpl_GetSchema( CSapSchemaObject ** ppObjSchema, CSapSchemaVerb ** ppverbSchema ) 
    { 
        return GetSchema( ppObjSchema, ppverbSchema ); 
    }

private:
    HRESULT GetSchemaVerbMethod( CSapSchemaVerb * verbSchema, BSTR Method, CSapSchemaVerb ** pverbSchema )
    {
        for(;;)
        {
           if( SAP_ID_SCHEMA_END == verbSchema->Type )
           {
               return E_FAIL;
           }
           if( verbSchema->Type == SAP_ID_SCHEMA_METHOD &&
               wcsicmp( Method, verbSchema->Name ) == 0 )
           {
               break;
           }
	   verbSchema++;
        }
        *pverbSchema = verbSchema;
        return S_OK;
    }

    HRESULT GetSchemaVerbMethodParameter( CSapSchemaVerb * verbSchema, BSTR Parameter, CSapSchemaVerb ** pverbSchema )
    {
        if( SAP_ID_SCHEMA_METHOD != verbSchema->Type )
        {
            return E_FAIL;
        }
        // goto parameters
        verbSchema++;
        for(;;)
        {
           if( SAP_ID_SCHEMA_PARAMETER != verbSchema->Type )
           {
               return E_FAIL;
           }
           if( wcsicmp( Parameter, verbSchema->Name ) == 0 )
           {
               break;
           }
	   verbSchema++;
        }
        *pverbSchema = verbSchema;
        return S_OK;
    }

    HRESULT GetSchemaVerbParameter( BSTR Method, BSTR Parameter, CSapSchemaVerb ** pverbSchema )
    {
        HRESULT hr;
        CSapSchemaObject * objSchema;
        CSapSchemaVerb *   verbSchema;
        hr = GetSchema( &objSchema, &verbSchema );
        if( FAILED( hr ) )
             return hr;
        hr = GetSchemaVerbMethod( verbSchema, Method, &verbSchema );
        if( FAILED( hr ) )
             return hr;
        hr = GetSchemaVerbMethodParameter( verbSchema, Parameter, &verbSchema );
        if( FAILED( hr ) )
             return hr;
        *pverbSchema = verbSchema; 
        return hr;
    }

private:
    int  IsNull( VARIANT * pVar )
    {
        int b = 0;
        if( NULL == pVar )
            return 1;
        if((VT_BYREF|VT_VARIANT) ==  V_VT(pVar))
        {
            pVar = V_VARIANTREF( pVar );
            if( NULL == pVar )
               return 1;
        }
        if( V_ISBYREF(pVar) && (NULL == V_BYREF(pVar)))
        {
            return 1;
        }
        switch(V_VT(pVar))
        {
        case VT_DISPATCH|VT_BYREF :
        case VT_UNKNOWN|VT_BYREF :
            if (NULL == *V_DISPATCHREF(pVar))
            {
                b = 1;
            }
            break;
        case VT_DISPATCH:
        case VT_UNKNOWN:
            if( NULL == V_DISPATCH(pVar) )
            {
                b = 1;
            }
            break;
        case VT_BSTR|VT_BYREF :
            if( NULL == *V_BSTRREF(pVar))
            {
                b = 1;
            }
			break;
        case VT_BSTR:
            if( NULL == V_BSTR(pVar))
            {
                b = 1;
            }
            break;
        default:
            switch(V_VT(pVar) & VT_TYPEMASK)
            {
            case VT_EMPTY:
            case VT_NULL:
            case VT_ERROR:
                b = 1;
                break;
            }
            break;
        }
        return b;
    }

    void SetToNothing( VARIANT * pVar)
    {
        //set to Nothing
        switch(V_VT(pVar))
        {
        case VT_DISPATCH|VT_BYREF:
        case VT_UNKNOWN|VT_BYREF:
            if (*V_DISPATCHREF(pVar))
            {
                (*V_DISPATCHREF(pVar))->Release();
                (*V_DISPATCHREF(pVar)) = NULL;
            }
            V_VT(pVar)       = VT_DISPATCH|VT_BYREF; 
            break ;
        default:
            VariantClear(pVar);
            V_VT(pVar)       = VT_DISPATCH; 
            V_DISPATCH(pVar) = NULL;
        }
        return;
    }

    void SetToType( VARIANT * pVar, VARTYPE oleType )
    {
        VariantClear( pVar );
        V_VT(pVar) = oleType;
    }

    void MoveIDispatchToVariant( VARIANT* pVar, IDispatch * pIDispatch )
    {
        if (V_VT(pVar) & VT_BYREF)
                *V_DISPATCHREF(pVar) = pIDispatch;
        else    
                V_DISPATCH(pVar) = pIDispatch;
        return;
    }


public:
    void _CleanUpForLeakTest()
    {
        Reset();
		m_ResourceDispenser.Release();
        CRfcResourceDispenser::_CleanUpForLeakTest();
        SetComplete();
    }
 
    STDMETHOD( SetRfcHandle )( unsigned long handle )
    {
        RFC_HANDLE hRfc = (RFC_HANDLE) handle;
        HRESULT hr;
        hr = checkResource();
        if( SUCCEEDED( hr ) )
        {
           hr = m_iSAPrfcContext->SetRFC_HANDLE( hRfc );
        }
        return hr;
    }
	// @cmember gives a appropriate RFC handle of the object or RFC_HANDLE_NULL 
    // from the resource dispenser. Can be used, if some special calls from the
    // RFC API are needed.
    RFC_HANDLE GetRFC_HANDLE()
    {
        CSapController c(g_szSAPMTX_H);
        RFC_HANDLE hRfc = RFC_HANDLE_NULL;
        checkResource() >> XLine(c);
        m_iSAPrfcContext->GetRFC_HANDLE( &hRfc ) >> XLine(c); 
        return hRfc;
    }

    // internal use within automatically generated proxy classes
    void SetRFC_HANDLE( RFC_HANDLE hRfc )
    {
        HRESULT hr;
        hr = checkResource();
        if( SUCCEEDED( hr ) )
        {
           hr = m_iSAPrfcContext->SetRFC_HANDLE( hRfc );
        }
        return;
    }

	STDMETHOD(GetRfcContext)(/*[out] */IUnknown **pRfcContext)    
    {
		HRESULT hr = checkResource();
		*pRfcContext = m_iSAPrfcContext.p;
		m_iSAPrfcContext.p->AddRef();
 		return hr;
    }

	STDMETHOD( SetRfcContext)(	/*[in] */IUnknown *pRfcContext)    
    {
		m_iSAPrfcContext = pRfcContext;
		if(! m_iSAPrfcContext)
			return E_FAIL;
		m_Bound = 1;
        return S_OK;
    }

    STDMETHOD(GetSurrogateProcessId)(/*[in] */unsigned long *pProcessId  )
    {
		*pProcessId = GetCurrentProcessId();
		return S_OK;
    }

	STDMETHOD(SetRfcSession)(/*[in] */IUnknown *pRfcSession,unsigned long lCookie)    
    {
		HRESULT hr = S_OK;
		m_RfcSession = pRfcSession;
		if(!m_RfcSession)
		{
			return E_FAIL;
		}
		m_Cookie = lCookie;
        return S_OK;
    }

    STDMETHOD( ReleaseRfcContext)(  )
    {
        if( FALSE == !m_iSAPrfcContext ) 
        {
            if(!m_RfcSession)
	            m_iSAPrfcContext->FreeResource();
            m_iSAPrfcContext.Release();
        }
        m_Bound       = 0;
		return S_OK;
    }


	STDMETHOD( ClearInvalidRef)(/*[in] */unsigned long lCookie)    
    {
		if(FALSE == !m_RfcSession)
		{
			m_RfcSession.Release();
			m_Cookie = 0;
		}
        return S_OK;
    }

    // @cmember reset everything on error.
    STDMETHOD(SetAbort)()
    {
		HRESULT hr = S_OK;
        if( FALSE == !m_iSAPrfcContext )
        {
            hr = m_iSAPrfcContext->SetAbort();
        }
		Reset();
        return hr;
    }
    // @cmember completes transaction.
    STDMETHOD(SetComplete)()
    {
		HRESULT hr = S_OK;
        if( FALSE == !m_iSAPrfcContext )
        {
            m_iSAPrfcContext->SetComplete();
        }
        Reset();
        return hr;
    }
    // @cmember enable transaction .
	STDMETHOD(EnableCommit)()
    {
		HRESULT hr = S_OK;
        if( FALSE == !m_iSAPrfcContext )
        {
			hr = m_iSAPrfcContext->EnableCommit();
		}
        ReleaseRfcContext();
        return hr;
    }


    // @cmember Creates a new empty table.
    // @ex This can be used to build a 'DimAs' method, which can give you a fully typed table | 
    // 
    // HRESULT CTest::DimAsXXXX( /*[out]*/ VARIANT * pOutputTable )   // an (empty) output table
    // {
    //
    //    try
    //    {
    //          Data(  L"TABLE_XXXX", &type_XXXX, pOutputTable );  
    //    }
    //    catch( HRESULT hr )
    //    {
    //        return hr;
    //    }
    //
    //    return S_OK;
    // }
    template< class RTYPE > void Data( wchar_t *wszName, CAbapType< RTYPE > * pType, VARIANT* pVar)
    {
        CSapController      c(g_szSAPMTX_H);
        CComPtr<ISAPrfcITab> pItab;
        //set to Nothing
        SetToNothing( pVar);
        // make sure the resource dipenser is loaded
        // (you need no resource dispenser her, but loading RD
        //  makes sure you have the rigth DLL).
        checkRD();
        // an empty table
        CAbapTable< RTYPE > itab( pType );
        LPDISPATCH prec = NULL;
        itab.getRDSRecordSet( &prec ) >> XLine(c);
        MoveIDispatchToVariant( pVar, prec );
    }

    // @cmember Creates a new empty table corresponding to a parameter.
    //
    // @comm
    // The macro DECLARE_SAP_SCHEMA_OBJECT must be set within the definition of the 'business object'
    // for this force to work. Also a complete schema definition using th macros
    // SAP_BEGIN_SCHEMA_OBJECT, SAP_SCHEMA_METHOD, SAP_SCHEMA_PARAMETER, SAP_SCHEMA_PARAMETER_STRUCT,
    // SAP_END_SCHEMA_OBJECT
    // must be available.
    // 
    // @ex This can be used to build a 'DimAs' method, which can give you a fully typed table | 
    // 
    // HRESULT CTest::DimAs( BSTR Method, BSTR Parameter,VARIANT * pOutputTable ) // an (empty) output table
    // {
    //
    //    try
    //    {
    //          DataLike( Method, Parameter, pOutputTable );  
    //    }
    //    catch( HRESULT hr )
    //    {
    //        return hr;
    //    }
    //
    //    return S_OK;
    // }
    void DataLike( BSTR Method, BSTR Parameter, VARIANT* pVar)
    {
        CSapController c(g_szSAPMTX_H);
        //set to Nothing
        SetToNothing( pVar);
        // make sure the resource dipenser is loaded
        // (you need no resource dispenser her, but loading RD
        //  makes sure you have the rigth DLL).
        checkRD();
        CAnyAbapType   * pType;
        CSapSchemaVerb * verbSchema;
        GetSchemaVerbParameter( Method, Parameter, &verbSchema ) >> XLine(c);
        if( NULL == verbSchema->AbapType )
        {
            SetToType( pVar, verbSchema->OleType );
        }
        else
        {
            pType = verbSchema->AbapType;
            // an empty table
            CAnyAbapTable< CAnyAbapType > itab( pType );
            LPDISPATCH prec = NULL;
            itab.getRDSRecordSet( &prec ) >> XLine(c);
            MoveIDispatchToVariant( pVar, prec );
        }
    }

    // @cmember start a function call. The function name must be given as wide char string
    HRESULT CallFunction( wchar_t * functionName, BOOL bSync = FALSE  )
    {
        CSapController c(g_szSAPMTX_H);
        checkResource()   >> XLine(c);
		if(m_uRfcType && !bSync)
		{

			CComQIPtr< ISAPrfcContext2,&IID_ISAPrfcContext2> pISAPrfcContext2(m_iSAPrfcContext);
			if(!pISAPrfcContext2)
			{
				AtlReportError( GUID_NULL,
									   "TRfc or QRfc not supported.",
									   GUID_NULL,
									   E_FAIL );
				E_FAIL >> XLine(c);
			}
			if(!m_TID.Length())
			{
				AtlReportError( GUID_NULL,
									   "TID not set.",
									   GUID_NULL,
									   E_FAIL );
				E_FAIL >> XLine(c);
			}
			if(1 == m_uRfcType) //TRfc
				pISAPrfcContext2->AbapInvokeStartTFunction( functionName,m_uRfcType,m_TID) >> XLine(c);
			else if(2 == m_uRfcType ) //QRfc
				pISAPrfcContext2->AbapInvokeStartQFunction( functionName,m_uRfcType,m_TID,m_QName, m_QCount) >> XLine(c);
		}
		else
			m_iSAPrfcContext->AbapInvokeStartFunction( functionName ) >> XLine(c);
        return S_OK;
    }

    // @cmember Exports named parameters to a function call. 
    // PTYPE is the parameter type. All automation datatypes 
    // including variants are supported.
    // Automatic mapping to standard ABAP data types.
    template< class PTYPE > HRESULT Exporting( wchar_t * parameter, PTYPE field )
    {
        CSapController c(g_szSAPMTX_H);
        CComVariant variant( field ); 
        checkResource()   >> XLine(c);
        m_iSAPrfcContext->AbapInvokeSimpleParameterByName(     RFCPAR_FUNCTION_INPUT,
                                                               parameter,
                                                               NULL,
                                                               VT_EMPTY,
                                                               &variant )   >> XLine(c);
        
        return S_OK;
    }

    // @cmember Imports named parameters from a function call. Outgoing parameters should 
    // always be variants. The variant type to choose can be given as parameter. If not,
    // the type of the variant itself is chosen.
    // 
    HRESULT Importing( wchar_t * parameter, VARIANT * pVariant, VARTYPE vartype = VT_EMPTY )
    {
        CSapController c(g_szSAPMTX_H);
        checkResource() >> XLine(c);
        m_iSAPrfcContext->AbapInvokeSimpleParameterByName(  RFCPAR_FUNCTION_OUTPUT,
                                                            parameter,
                                                            NULL,
                                                            vartype,
                                                            pVariant )
                                                                >> XLine(c);
        return S_OK;
    }  

    // @cmember Exports named parameters to a function call. 
    // PTYPE is the parameter type. All automation datatypes 
    // including variants are supported.
    // The ABAP data type to choose must be given as a parameter.
    //
    // @comm
    // For every ABAP data type where there is no one-to-one relationship to
    // OLE data types thís version of the Exporting function has to be choosen.
    // This includes TYPE N, TYPE P and TYPE T.
    //
    // @xref <t CAbapScalarType>
    template< class PTYPE > HRESULT Exporting( wchar_t * parameter, CAbapScalarType * pType, PTYPE field )
    {
        CSapController c(g_szSAPMTX_H);
        CComVariant variant( field ); 
        checkResource()   >> XLine(c);
        m_iSAPrfcContext->AbapInvokeSimpleParameterByName(     RFCPAR_FUNCTION_INPUT,
                                                               parameter,
                                                               pType->getType(),
                                                               VT_EMPTY,
                                                               &variant )   >> XLine(c);
        return S_OK;
    }

    // @cmember Imports named parameters from a function call. Outgoing parameters should 
    // always be variants. The variant type to choose can be given as parameter. If not,
    // the type of the variant itself is chosen.
    // The ABAP data type of the parameter of the function must be given as a parameter. 
    //
    // @comm
    // For every ABAP data type where there is no one-to-one relationship to
    // OLE data types thís version of the Exporting function has to be choosen.
    // This includes TYPE N, TYPE P and TYPE T.
    //
    // @xref <t CAbapScalarType>
    HRESULT Importing( wchar_t * parameter, CAbapScalarType * pType, VARIANT * pVariant, VARTYPE vartype = VT_EMPTY )
    {
        CSapController c(g_szSAPMTX_H);
        checkResource() >> XLine(c);
        m_iSAPrfcContext->AbapInvokeSimpleParameterByName(  RFCPAR_FUNCTION_OUTPUT,
                                                            parameter,
                                                            pType->getType(),
                                                            vartype,
                                                            pVariant )
                                                                >> XLine(c);
        return S_OK;
    }  

    // @cmember Exports a table as a named parameter to a function or method call. The table must be a COM object 
    // either supporting a OLEDB Rowset or a ADO Recordset interface. 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ExportingTable(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, IDispatch * extab )
    {
		CComVariant variant = extab;
		return ExportingTable( parameter, pRowType, variant );
    }

    // @cmember Exports a table as a named parameter to a function or method call. The table must be a COM object 
    // either supporting a OLEDB Rowset or a ADO Recordset interface. 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ExportingTable(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT extab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        m_iSAPrfcContext->AbapInvokeTableByName( RFCPAR_FUNCTION_INPUT,
                                                 parameter,
                                                 iSAPrfcStructDesc,
                                                 &extab )   >> XLine(c);
        return S_OK;
    }

    // @cmember Imports a table as a named parameter from a function or method call. The table will be set to a COM object 
    // implementing a OLEDB Rowset and a ADO Recordset interface using RDS ("Remote Data Service") or to "nothing". 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ImportingTable(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT * pImTab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        m_iSAPrfcContext->AbapInvokeTableByName( RFCPAR_FUNCTION_OUTPUT,
                                                 parameter,
                                                 iSAPrfcStructDesc,
                                                 pImTab )   >> XLine(c);
        return S_OK;
    }

    // @cmember Imports and export a table as a named parameter from/to a function or method call. The table must be a COM object 
    // implementing a OLEDB Rowset or a ADO Recordset interface or it must be set to "nothing". 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ChangingTable(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT * pChanTab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        if( !IsNull(pChanTab) )
        {
            m_iSAPrfcContext->AbapInvokeTableByName( RFCPAR_FUNCTION_INPUT,
                                                     parameter,
                                                     iSAPrfcStructDesc,
                                                     pChanTab )   >> XLine(c);
        }
        m_iSAPrfcContext->AbapInvokeTableByName( RFCPAR_FUNCTION_OUTPUT,
                                                 parameter,
                                                 iSAPrfcStructDesc,
                                                 pChanTab )   >> XLine(c);
        return S_OK;
    }

    // @cmember Imports and export a structure as a named parameter from/to a function or method call. The structure must be 
    // represented by a COM object implementing a OLEDB Rowset or a ADO Recordset interface 
    // or it must be set to "nothing". 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ChangingStructure(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT * pChanTab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        if( !IsNull(pChanTab) )
        {
            m_iSAPrfcContext->AbapInvokeStructureByName( RFCPAR_FUNCTION_INPUT,
							 parameter,
							 iSAPrfcStructDesc,
							 pChanTab )   >> XLine(c);
        }
        m_iSAPrfcContext->AbapInvokeStructureByName( RFCPAR_FUNCTION_OUTPUT,
						     parameter,
						     iSAPrfcStructDesc,
						     pChanTab )   >> XLine(c);
        return S_OK;
    }

    
    // @cmember Exports the structure of a row of a table as a named parameter to a function or method call. The table must be a COM object 
    // either supporting a OLEDB Rowset or a ADO Recordset interface. It must contain exactly one row.
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ExportingStructure(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT extab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        m_iSAPrfcContext->AbapInvokeStructureByName( RFCPAR_FUNCTION_INPUT,
                                                     parameter,
                                                     iSAPrfcStructDesc,
                                                     &extab )   >> XLine(c);
        return S_OK;
    }

    // @cmember Exports the structure of a row of a table as a named parameter to a function or method call. The table must be a COM object 
    // either supporting a OLEDB Rowset or a ADO Recordset interface. It must contain exactly one row.
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ExportingStructure(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, IDispatch * extab )
    {
		CComVariant variant = extab;
		return ExportingStructure( parameter, pRowType, variant );
    }

    // @cmember Imports a structure as a named parameter from a function or method call. The structure will be put into a COM object 
    // implementing a OLEDB Rowset and a ADO Recordset interface using RDS or to "nothing". 
    // The template parameter RTYPE is the type of a row of the table. 
    template< class RTYPE > HRESULT ImportingStructure(wchar_t * parameter,  CAbapType<RTYPE> * pRowType, VARIANT * pImTab )
    {
        CSapController c(g_szSAPMTX_H);
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc; 
        checkResource()   >> XLine(c);
        pRowType->getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
        m_iSAPrfcContext->AbapInvokeStructureByName( RFCPAR_FUNCTION_OUTPUT,
                                                     parameter,
                                                     iSAPrfcStructDesc,
                                                     pImTab )   >> XLine(c);
        return S_OK;
    }
    
    void InitOutput( VARIANT * pVariant )
    {
        if( pVariant != NULL )
            ::VariantInit( pVariant ); 
        return;
    }

    // @cmember Exports and imports named parameters to/from a function call
    HRESULT Changing( wchar_t * parameter, VARIANT * pVariant, VARTYPE vartype = VT_EMPTY )
    {
        CSapController c(g_szSAPMTX_H);
        checkResource() >> XLine(c);
        m_iSAPrfcContext->AbapInvokeSimpleParameterByName(  RFCPAR_FUNCTION_INOUT,
                                                            parameter,
                                                            NULL,
                                                            vartype,
                                                            pVariant )
                                                                    >> XLine(c);
        return S_OK;
    }

    // @cmember Exports and imports named parameters to/from a function call
    HRESULT Changing( wchar_t * parameter, CAbapScalarType * pType, VARIANT * pVariant, VARTYPE vartype = VT_EMPTY )
    {
        CSapController c(g_szSAPMTX_H);
        checkResource() >> XLine(c);
        if( IsNull( pVariant ) )
        {
            return Importing( parameter, pType, pVariant, vartype );
        }
        else
        {
            m_iSAPrfcContext->AbapInvokeSimpleParameterByName(  RFCPAR_FUNCTION_INOUT,
                                                                parameter,
                                                                pType->getType(),
                                                                vartype,
                                                                pVariant )
                                                                    >> XLine(c);
        }
        return S_OK;
    }  

    // @cmember executes the function call.
    // Must be the last function in a sequence of Exporting and/or Importing function calls.
    HRESULT EndCallFunction( )
    {
		HRESULT hr;
        CSapController c(g_szSAPMTX_H);
        checkResource()  >> XLine(c);
        hr = m_iSAPrfcContext->AbapInvokeExecute();
	// check for exceptions
		if( E_FAIL == hr ) throw hr;

	// check for errors
		hr >> XLine(c);
		if(!m_KeepSAPContext)
			EnableCommit();
        return S_OK;
    }

    template< class RTYPE > ISAPrfcStructDesc * Type( CAbapType< RTYPE > * pType )
    {
        CSapController      c(g_szSAPMTX_H);
        ISAPrfcStructDesc * pStruct;
        pType->getISAPrfcStructDesc( &pStruct ) >> XLine(c);
        return pStruct;
    }
    // @comm The general syntax for the overloaded Exporting/Importing functions is
    //
    // Exporting... ( parameter name, [abap data type,] value )
    //
    // and
    //
    // Importing... ( parameter name, [abap data type,] pointer to value [, variant type] ) 
    //
protected:
	virtual HRESULT InternalAdviseRfcGuiSink(IDispatch* pIRfcGuiSink, short AbapDebug,short UseSapGui)
    {
        HRESULT hr = checkResource();
		if(SUCCEEDED(hr))
        {
			CComPtr< IDispatch> m_pIRfcGuiSink = pIRfcGuiSink;
			return m_iSAPrfcContext->AdviseRfcGuiSink(pIRfcGuiSink,AbapDebug,UseSapGui);
        }
		return S_FALSE;
    }

    HRESULT checkRD()
    {
        HRESULT hr;
        if( !m_ResourceDispenser )
        {
            hr = CRfcResourceDispenser::GetContextSource( &m_ResourceDispenser );
        }
        else 
            hr = S_OK;
        return hr;
    }

    HRESULT checkResource()
    {
        HRESULT hr;
        if( !m_iSAPrfcContext )
        {
			if(FALSE == !m_RfcSession)
			{
				hr = m_RfcSession->GetRfcContext((IUnknown **)&(m_iSAPrfcContext.p));
			}
			else
			{
				hr = checkRD();
				if( SUCCEEDED( hr ) )
				{
					if(!m_Destination.Length())
					        checkDefaultDestination();
					hr = m_ResourceDispenser->Get( (BSTR) m_Destination, 
												   (BSTR)m_UserID, (BSTR)m_Password, (BSTR)m_Language,(BSTR)m_Client,NULL, 
												   &m_iSAPrfcContext, &IID_ISAPrfcContext );
				}
			}
        }
        else 
            hr = S_OK;
        if( SUCCEEDED( hr ) )
        {
            m_Bound = 1;
        }
        return hr;
    }

protected:
    void checkDefaultDestination()
    {
			//      If the default destination has been set in the system registry, use its value as default
		LONG rc = ERROR_SUCCESS;
		CRegKey rkDefaultDes;
		DWORD   lType;
		LPWSTR szTextaulCLSID = NULL;
		_TCHAR szKey[1024] = ( _T("Software\\SAP\\MTS\\Components\\%") RFC_PRINTF_OLES _T("\\Destination"));
		_TCHAR szTemp[1024] = _T("");
		_TCHAR szValue[1024] = _T("");
		DWORD dwValueLength = sizeof(szValue)/sizeof(_TCHAR);
		StringFromCLSID(GetObjectCLSID(), &szTextaulCLSID);
		_stprintf(szTemp,szKey,szTextaulCLSID);
			if( NULL != szTextaulCLSID ) CoTaskMemFree( szTextaulCLSID );      
		rkDefaultDes.Open(HKEY_LOCAL_MACHINE,szTemp, KEY_READ);
		rc = rkDefaultDes.QueryValue(szValue,NULL,&dwValueLength);
		if(ERROR_SUCCESS == rc   && _tcslen(szValue))
		{
			_tcscpy(szKey, _T("Software\\SAP\\MTS\\Destination"));
			rkDefaultDes.Open(HKEY_LOCAL_MACHINE,szKey, KEY_READ);
			dwValueLength = sizeof(szValue);
			szTemp[0] = _T('\0');
			//rc = rkDefaultDes.QueryValue(szTemp,szValue,&dwValueLength); // If the type is not *_SZ, there will be a assertion for debug build 
			rc = RegQueryValueEx(rkDefaultDes.m_hKey,szValue,NULL,&lType,(LPBYTE)szTemp,&dwValueLength);
			if(ERROR_SUCCESS == rc && _tcslen(szTemp))
			{
				m_Destination = szValue;
			}
		}
    }

private:
    // COM pointer to RFC connection (CComPtr does automatic Release)
protected:
    CComPtr< ISAPrfcContextSource > m_ResourceDispenser;
    CComQIPtr< ISAPrfcContext,&IID_ISAPrfcContext>       m_iSAPrfcContext; 
    CComQIPtr< ISAPrfcBind,&IID_ISAPrfcBind>       m_RfcSession; 
    //ISAPrfcBind* m_RfcSession; 
public:
    CComBSTR                        m_Destination;
    CComBSTR                        m_UserID;
    CComBSTR                        m_Password;
    CComBSTR                        m_Language;
    CComBSTR                        m_Client;
    int                             m_Bound;
	unsigned long                   m_Cookie; // object's own id in session
	VARIANT_BOOL					m_KeepSAPContext;
    CComBSTR                        m_TID;
    CComBSTR                        m_QName;
    DWORD                           m_QCount;
	UINT                            m_uRfcType; //0: sync RFC, 1: TRfc, 2: QRfc

};    


/* @enum SapConnectorRegistryEntryKey |
 *
 * Available registry entries for DCOM Connector objects.
 * To be used within BEGIN_SAP_REGISTRY_MAP. SR_ prefix has to
 * be omitted there.
 * 
 * 
 */
enum SapConnectorRegistryEntryKey
{
    SAP_REGISTRY_ENTRY_NULL = 0,
    SR_Interface = 1,              // @emem Interface ID.
    SR_Library,                    // @emem Type library ID.
    SR_BORClassVersion,            // @emem R/3 Class Version.
    SR_Package,                    // @emem Package Name
    SR_Progid,                     // @emem OLE ProgID.
    SR_System,                     // @emem Name of R/3 system.
    SR_Destination,                // @emem Default Destination.
    SR_CodeGeneratorVersion,       // @emem Version of Code Generator.
    SR_CreateUser,                 // @emem Creator user ID.
    SR_CreateTime,                 // @emem User ID, who did the last update.
    SR_InstallUser,                // @emem Creation time stamp.
    SR_InstallTime,                // @emem Last installation time stamp.
    SR_ClassName,                  // @emem Class Name in R/3
    SR_Description,                // @emem Description
    SR_PROGID,                     // ...
    SR_INTERFACE,
    SR_InstallDate,
    SR_LIBRARY,      
    SR_PACKAGE,
    SR_BOR_CLASSNAME
};

struct SapConnectorRegistryEntry
{
    SapConnectorRegistryEntryKey key;
    const _TCHAR * id;
    const _TCHAR * value;
};

class CSapRegistryHelper
{
private: 
    CSapRegistryHelper() {}
public:
    CSapRegistryHelper( const CLSID* pclsid, const IID* piid, 
		                const GUID* plibid,  CSapSchemaObject * pObjSchema )
    {
        m_pclsid                = pclsid; 
        m_piid                  = piid; 
        m_plibid                = plibid;
        m_pObjSchema            = pObjSchema;
    }
public:
    HRESULT SapSpecialUpdateRegistryEx(UINT nResID, SapConnectorRegistryEntry * registryEntries, BOOL update );

private:
    const CLSID      * m_pclsid; 
    const IID        * m_piid; 
    const GUID       * m_plibid;
    CSapSchemaObject * m_pObjSchema;
};


// @class Template class for MTS proxy objects of ABAP objects
// 
// @tcarg class | T | The derived class acting as a proxy
// @tcarg const CLSID * | pclsid | pointer to Class ID of the proxy
// @tcarg class | IF | The (standard) dual interface derived from <i ISAPConnector> 
// @tcarg const IID * | piid | pointer to interface id
// @tcarg const GUID * | plibid | pointer to id of the type library
//
// In a ATL environment you simply derive the ATL class from this class. CSapConnector 
// provides the implementation for the <c ISAPConnector> portion of 
// the dual interface on your object and  offers several methods for easily calling R/3
// functions. These methods handle all the connection management and
// the complete error handling internally. On errors they set IErrorInfo
// and throw a exception of type HRESULT.
// Also these methods handle all necessary conversions between OLE and 
// ABAP data types. 
// <c CSapConnector> is a derived class of <t CSapBaseProxy>,
// which implements most of the methods.
//
// In the BEGIN_COM_MAP don't forget to enter the macro 
// COM_INTERFACE_ALL_SAP_ENTRIES. This leads to some interfaces as ISupportErrorInfo
// being automatically created.
//
// @ex The following example shows a typical ATL class using <c CSapConnector>. First, you define 
//     the dual interface on your object in your IDL file. Instead of using  IDispatch as the base
//     interface, you derive the the dual interface from interface <c ISAPConnector>. This interface
//     is defined in the file sapconn.idl, which can be found in RFC SDK's include directory. This 
//     file must be imported into your IDL file. Also note that the method IDs above 1000 are reserved
//     for the methods in the base interface. All output parameters must be variants. Input parameters
//     can be any automation data type. Tables are either OLEDB Rowsets or ADO Recordsets | 
//
// import "oaidl.idl";
// import "ocidl.idl";
// import "sapconn.idl";  //add this
//	[
//		object,
//		uuid(F866E062-64B6-11D1-B767-00A0C9308BE6),
//		dual,
//		helpstring("ITest Interface"),
//		pointer_default(unique)
//	]
//	//interface ITest : IDispatch    // remove this
//	interface ITest : ISAPConnector  // add this
//	{
//		[id(1), helpstring("method SomeFunction")] HRESULT SomeFunction([in] BSTR  testString,
//																		[in] VARIANT   inputTable,      
//																		[out] VARIANT * pTestStringOut, 
//																		[out] VARIANT * pOutputTable )   
//
//      ...
//
//	};
//
// 
// class ATL_NO_VTABLE CTest : 
//        public CSapConnector<CTest, &CLSID_Test, 
//                             ITest, &IID_ITest, &LIBID... >, // add this
//        // public CComObjectRootEx<CComSingleThreadModel>,      // remove this
//        // public CComCoClass<CTest, &CLSID_Test>,              // remove this
//        // public IDispatchImpl<ITest, &IID_ITest, &LIBID... >  // remove this
//
// public:
//	CR3Test()
//	{
//	}
//
// // DECLARE_REGISTRY_RESOURCEID(IDR_TEST)   // remove this
// DECLARE_REGISTRY_SAP_RESOURCEID(IDR_TEST)   // add this
// DECLARE_NOT_AGGREGATABLE(CTest)
//
// BEGIN_COM_MAP(CR3Test)
//	COM_INTERFACE_ENTRY(ITest)
//	COM_INTERFACE_ENTRY2(IDispatch, ITest )
//      COM_INTERFACE_ALL_SAP_ENTRIES      // use this macro to expose all additional interfaces
// END_COM_MAP()
//
// ...
// // a typical member function calling some function module in R/3
// // having as input parameter a string and a table and which sends
// // back the same.
// HRESULT CTest::SomeFunction( /*[in]*/  BSTR      testString,      // character field
//                              /*[in]*/  VARIANT   inputTable,      // a table (Rowset or Recordset)
//                              /*[out]*/ VARIANT * pTestStringOut,  // an output string
//                              /*[out]*/ VARIANT * pOutputTable )   // an output table
// {
//
//    try
//    {
//        // initalize all output fields
//        VariantInit( pTestStringOut );
//        VariantInit( pOutputTable );
//
//        // Function SOMEFUNCTION
//
//        CallFunction( L"SOMEFUNCTION" );         
//          Exporting(  L"TESTSTRING",   testString );  
//          Exporting(  L"INPUTTABLE",   &type_XXXX, testString );  
//          Importing(  L"TESTSTRINGOUT" pTestStringOut, VT_BSTR );  
//          Importing(  L"OUTPUTTABLE",  &type_XXXX, pOutputTable );  
//        EndCallFunction();                 
//       
//    }
//    catch( HRESULT hr )
//    {
//        return hr;
//    }
//
//    return S_OK;
// }
//
//
// @xref <t CSapBaseProxy>, <i ISAPConnector>, <i ISAPSession>,
// <om ISAPConnector.AdviseRfcGuiSink>, <om ISAPConnector.PutSessionInfo>  .
//
template <class T, const CLSID* pclsid, class IF, const IID* piid, const GUID* plibid, const RFC_CALL_TYPE uRfcType = SYNC_RFC>
class CSapConnector : public CSapBaseProxy< T, pclsid,uRfcType>,
                      public IDispatchImpl< IF, piid, plibid >
{
public:
    CSapConnector()
    {
        // check default destination
    }

protected:
    static CSapRegistryHelper * SapConnectorGetNewHelper(CSapSchemaObject * pObjSchema)
    {
        CSapRegistryHelper * pHelper = new CSapRegistryHelper( pclsid, piid, plibid, pObjSchema );
        return pHelper;
    }


protected:
    static const CLSID* GetCLSID(); 
   
public:
    STDMETHOD( InterfaceSupportsErrorInfo )( REFIID riid )
    {
        // support error info for all interfaces
        return S_OK;
    }

public:
    STDMETHOD( get_Destination) ( BSTR * pVal)
    {
	*pVal = m_Destination.Copy();
        return S_OK;
    }
        
    STDMETHOD( put_Destination) ( BSTR newVal )
    {
		if( !m_Bound && !m_RfcSession)
		{
			m_Destination = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }


    STDMETHOD( get_UserID) ( BSTR * pVal)
    {
		*pVal = m_UserID.Copy();
        return S_OK;
    }
        
    STDMETHOD( put_UserID) ( BSTR newVal )
    {
		if( !m_Bound && !m_RfcSession)
		{
			m_UserID = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

        
    STDMETHOD( put_Password) ( BSTR newVal )
    {
		if( 0 == m_Bound )
		{
			m_Password = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

    STDMETHOD( get_Language) ( BSTR * pVal)
    {
		*pVal = m_Language.Copy();
        return S_OK;
    }
        
    STDMETHOD( put_Language) ( BSTR newVal )
    {
		if( !m_Bound && !m_RfcSession)
		{
			m_Language = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

    STDMETHOD( get_Client) ( BSTR * pVal)
    {
		*pVal = m_Client.Copy();
        return S_OK;
    }
        
    STDMETHOD( put_Client) ( BSTR newVal )
    {
		if( !m_Bound && !m_RfcSession)
		{
			m_Client = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

	STDMETHOD( PutSessionInfo )(BSTR Destination,BSTR UserID,BSTR Password,BSTR Language,BSTR Client )
	{
		if( !m_Bound && !m_RfcSession)
		{
			m_Destination = Destination;
			m_UserID = UserID;
			m_Password = Password;
			m_Language = Language;
			m_Client = Client;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

    STDMETHOD( AdviseRfcGuiSink )(IDispatch* pIRfcGuiSink, short AbapDebug,short UseSapGui )
    {
		return InternalAdviseRfcGuiSink(pIRfcGuiSink,AbapDebug,UseSapGui);
    }

    STDMETHOD( CommitWork )()
    {
		if(FALSE == !m_RfcSession)
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
		if(!m_KeepSAPContext)
		{
            return AtlReportError( GUID_NULL,
                                   "Property KeepSAPContext is FALSE.",
                                   *piid,
                                   E_FAIL );
		}
        try
        {
            if (0 != m_Bound)
            {
                CallFunction( L"ABAP4_COMMIT_WORK" );
                EndCallFunction();
            }
			EnableCommit();
        }
        catch( HRESULT hr )
        {
            SetAbort();
            return hr;
        }    
        return S_OK;
    }

	STDMETHOD( RollbackWork )()
    {
		if(FALSE == !m_RfcSession)
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
		if(!m_KeepSAPContext)
		{
            return AtlReportError( GUID_NULL,
                                   "Property KeepSAPContext is FALSE.",
                                   *piid,
                                   E_FAIL );
		}
        try
        {
            if (0 != m_Bound)
            {
                CallFunction( L"ABAP4_ROLLBACK_WORK" );
                EndCallFunction();
            }
            SetAbort();
        }
        catch( HRESULT hr )
        {
            SetAbort();
            return hr;
        }
        return S_OK;
    }

	STDMETHOD( CommitWorkAndWait )()
    {

        return E_NOTIMPL;
    }

    STDMETHOD( get_KeepSAPContext) ( VARIANT_BOOL * pVal)
    {
		*pVal = m_KeepSAPContext
			
			;
        return S_OK;
    }
        
    STDMETHOD( put_KeepSAPContext) ( VARIANT_BOOL newVal )
    {
		if( !m_Bound && !m_RfcSession)
		{
			m_KeepSAPContext = newVal;
			return S_OK;
		}
		else if(m_Bound)
		{
            return AtlReportError( GUID_NULL,
                                   "Object already bound to R/3.",
                                   *piid,
                                   E_FAIL );
		}
		else
		{
            return AtlReportError( GUID_NULL,
                                   "Object created in the session",
                                   *piid,
                                   E_FAIL );
		}
    }

	STDMETHOD(GetConnectionAttribute)(/*[in]*/BSTR AttrName,/*[out,retval] */VARIANT *pAttrValue)
	{
		HRESULT hr;
		if(FALSE == !m_iSAPrfcContext)
			return m_iSAPrfcContext->GetConnectionAttribute(AttrName,pAttrValue);
		else if(SUCCEEDED(hr = checkResource()))
		{
			hr = m_iSAPrfcContext->GetConnectionAttribute(AttrName,pAttrValue);
			if(SUCCEEDED( hr ))
				EnableCommit();
		}
		return hr;
	}

	STDMETHOD(GetNewTID)( BSTR *TID)
	{
       CSapController c(g_szSAPMTX_H);
       checkRD() >> XLine(c);
       CComQIPtr< ISAPrfcContextSource2,&IID_ISAPrfcContextSource2> pISAPrfcContextSource2(m_ResourceDispenser);
	   if(!pISAPrfcContextSource2)
	   {
			return AtlReportError( GUID_NULL,
								   "TRfc or QRfc not supported.",
								   *piid,
								   E_FAIL );
	   }
	   m_TID = CComBSTR(39,_T(""));	
	   HRESULT hr = pISAPrfcContextSource2->CreateTID(m_TID.m_str);
	   if(SUCCEEDED(hr))
		   *TID = m_TID.Copy();
	   return hr;
	}

    STDMETHOD( put_TID) ( BSTR newVal )
    {
		GUID gGuid;
		if(NULL == newVal || FAILED(CLSIDFromString(newVal,&gGuid)))
		{
            return AtlReportError( GUID_NULL,
                                   "Invalid parameter. TID must be a valid GUID.",
                                   *piid,
                                   E_FAIL );
		}
		m_TID = newVal;
		return S_OK;
    }

    STDMETHOD( get_TID) ( BSTR * pVal)
    {
		if(pVal)
		{
			*pVal = m_TID.Copy();
		}
		return S_OK;
    }

    STDMETHOD( put_QueueName) ( BSTR newVal )
    {
		USES_CONVERSION;
		if(newVal && wcslen(newVal) && RFC_QNAME_LN > wcslen(newVal))
		{
			TCHAR szTemp[RFC_QNAME_LN + 1];
			_tcscpy(szTemp, W2T(newVal));
			m_QName = CharUpper(szTemp);
		}
		else 
			return AtlReportError( GUID_NULL,
								   "Invalid Queue name.",
								   *piid,
								   E_FAIL );
		return S_OK;
    }

    STDMETHOD( get_QueueName) ( BSTR * pVal)
    {
		// set computer name as default queue name
		if(!m_QName.Length())
		{
			TCHAR szComputer[256];
			DWORD dwLen = 256;
			GetComputerName(szComputer,&dwLen);
			m_QName = CharUpper(szComputer);
		}
		*pVal = m_QName.Copy();
		return S_OK;
    }

    STDMETHOD( put_QueueItemIndex) ( long newVal )
    {
    if (newVal < 0)
      return E_INVALIDARG;

		m_QCount = newVal;
		return S_OK;
    }

    STDMETHOD( get_QueueItemIndex) ( long * pVal)
    {
		if(pVal)
			*pVal = m_QCount;
		return S_OK;
    }

    STDMETHOD( Confirm) ( BSTR TID)
    {
			//To do: Call RfcConfirmTID over Context?
		CSapController c(g_szSAPMTX_H);
		checkResource()   >> XLine(c);
		CComQIPtr< ISAPrfcContext2,&IID_ISAPrfcContext2> pISAPrfcContext2(m_iSAPrfcContext);
		if(!pISAPrfcContext2)
		{
			return AtlReportError( GUID_NULL,
								   "TRfc or QRfc not supported.",
								   *piid,
								   E_FAIL );
		}
		HRESULT hr = pISAPrfcContext2->ConfirmTID(TID ? TID : m_TID);
		if(FAILED(hr))
		{
			return AtlReportError( GUID_NULL,
								   "Confirm RFC TID failed.",
								   *piid,
								   E_FAIL );
		}
		return S_OK;
   }
	STDMETHOD( ActivateQueue) ( BSTR QueueName)
	{
		if(NULL == QueueName || !wcslen(QueueName) || RFC_QNAME_LN < wcslen(QueueName))
		{
			return AtlReportError( GUID_NULL,
								   "Invalid QueueName.",
								   *piid,
								   E_FAIL );
		}
		CComBSTR szTemp(QueueName);
 		CSapController c(g_szSAPMTX_H);
		try
		{
			checkResource()   >> XLine(c);
			CallFunction( L"QIWK_REGISTER", TRUE );
			Exporting(L"QNAME", CharUpperW(szTemp.m_str));
			EndCallFunction();
			if(!m_KeepSAPContext)
			{
				EnableCommit();
			}
		}
		catch(HRESULT hr)
		{
			return hr;
		}
		return S_OK;
	}
	STDMETHOD( DeactivateQueue) ( BSTR QueueName)
	{
		if(NULL == QueueName || !wcslen(QueueName))
		{
			return AtlReportError( GUID_NULL,
								   "Invalid QueueName.",
								   *piid,
								   E_FAIL );
		}
		CComBSTR szTemp(QueueName);
		//To do: Call RfcConfirmTID over Context?
		CSapController c(g_szSAPMTX_H);
		try
		{

			checkResource()   >> XLine(c);
			CallFunction( L"QIWK_UNREGISTER" ,TRUE);
			Exporting(L"QNAME", CharUpperW(szTemp.m_str));
			EndCallFunction();
			if(!m_KeepSAPContext)
			{
				EnableCommit();
			}
		}
		catch(HRESULT hr)
		{
			return hr;
		}
		return S_OK;
	}
};



template <class T, const CLSID* pclsid, class IF, const IID* piid, const GUID* plibid, const RFC_CALL_TYPE uRfcType>
const CLSID* CSapConnector< T,pclsid,IF,piid,plibid,uRfcType>::GetCLSID()
{
    return pclsid;
}

#define DECLARE_REGISTRY_SAP_RESOURCEID(x)\
        private:\
        static SapConnectorRegistryEntry ms_SapConnectorRegistryEntries[]; \
        public: \
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	   return SapConnectorUpdateRegistry(x, bRegister);\
	}\
        static HRESULT WINAPI SapConnectorUpdateRegistry( UINT nResID, BOOL bRegister )\
        {\
	        CSapSchemaObject * pObjSchema = getObjSchema();    \
            \
            CSapRegistryHelper * pHelper = SapConnectorGetNewHelper(pObjSchema);\
            HRESULT hr = pHelper->SapSpecialUpdateRegistryEx(nResID, ms_SapConnectorRegistryEntries, bRegister);\
            delete pHelper;   \
            return hr; \
        } 

#define DECLARE_REGISTRY_SAP_RESOURCEID_NO_MAP(x)\
        public: \
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{\
	   return SapConnectorUpdateRegistry(x, bRegister);\
	}\
        static HRESULT WINAPI SapConnectorUpdateRegistry( UINT nResID, BOOL bRegister )\
        {\
	        CSapSchemaObject * pObjSchema = getObjSchema();    \
            \
            CSapRegistryHelper * pHelper = SapConnectorGetNewHelper(pObjSchema);\
            HRESULT hr = pHelper->SapSpecialUpdateRegistryEx(nResID, NULL, bRegister);\
            delete pHelper;   \
            return hr; \
        } 

#define DECLARE_REGISTRY_SAP_RESOURCEID_NATIVE(x)\
        public: \
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
  {\
    return SapConnectorUpdateRegistry(x, bRegister);\
  }\
  static HRESULT WINAPI SapConnectorUpdateRegistry( UINT nResID, BOOL bRegister )\
  {\
    CSapRegistryHelper * pHelper = new CSapRegistryHelper(&(GetObjectCLSID()), NULL, NULL, NULL);\
    HRESULT hr = pHelper->SapSpecialUpdateRegistryEx(nResID, NULL, bRegister);\
    delete pHelper;   \
    return hr; \
  } 
       
// setting registry keys
#define BEGIN_SAP_REGISTRY_MAP( ClassName ) \
SapConnectorRegistryEntry ClassName::ms_SapConnectorRegistryEntries[] = {

#define SAP_REGISTRY_ENTRY( key, value ) \
{ SR_ ## key, #key, #value },

#define END_SAP_REGISTRY_MAP() \
{ SAP_REGISTRY_ENTRY_NULL, (_TCHAR *) 0, (_TCHAR *) 0 }};

// predeclaration
class CAnyAbapType;

// Schema description data 
struct CSapSchemaObject
{
	wchar_t*     Name;
    wchar_t*     CppName;
	wchar_t*     InternalName;
	const CLSID* pClsid;
	const IID*   pIid;       
	wchar_t*     Desc;
	wchar_t*     Version;
	wchar_t*     sapsystem;
	WORD         Flags;
};

enum SapSchemaId
{
    SAP_ID_SCHEMA_END       = 0,      // end of array
    SAP_ID_SCHEMA_PARAMETER = 'P',    // Parameter
    SAP_ID_SCHEMA_KEY       = 'K',    // Schlüsselfeld	
    SAP_ID_SCHEMA_ATTRIBUTE = 'A',    // Attribut	
    SAP_ID_SCHEMA_METHOD    = 'M',    // Methode
    SAP_ID_SCHEMA_EVENT     = 'E',    // Event
    SAP_ID_SCHEMA_EXCEPTION = 'X'     // Exception
};

struct CSapSchemaVerb
{
	SapSchemaId   Type; //'K' 'M' 'P'
	wchar_t*      Name;
	wchar_t*      InternalName;
	unsigned long Dispid;
	wchar_t*      Desc;
	VARTYPE       OleType;
	RFCTYPE       RfcType;
	wchar_t*      RefStruct;
	CAnyAbapType* AbapType;
	unsigned int  Length;
	unsigned int  Decimals;
	WORD          Flags;
};


#define SAP_ID_SCHEMA_NULL           0x0000
#define SAP_ID_SCHEMA_SCALAR         0x0001		// parameter or attribute is scalar
#define SAP_ID_SCHEMA_STRUCTURE      0x0002		// parameter or attribute is structure
#define SAP_ID_SCHEMA_TABLE          0x0004		// parameter or attribute is table
#define SAP_ID_SCHEMA_OPTIONAL       0x0008		// parameter optional
#define SAP_ID_SCHEMA_EXPORT         0x0010		// parameter is exported
#define SAP_ID_SCHEMA_IMPORT         0x0020		// parameter is imported
#define SAP_ID_SCHEMA_RESULT         0x0040		// method has result
#define SAP_ID_SCHEMA_BAPI           0x0080		// method is part of the BAPI
#define SAP_ID_SCHEMA_DIALOG_METHOD  0x0100		// method sends dialog
#define SAP_ID_SCHEMA_CLASS_METHOD   0x0200		// method is class method, not instance dependant
#define SAP_ID_SCHEMA_FACTORY_METHOD 0x0400		// method is factory method, creates an persistent instance 
#define SAP_ID_SCHEMA_LOCAL_METHOD   0x0800		// method works on local instance and does not call R/3
#define SAP_ID_SCHEMA_OBSOLETE       0x1000		// method or object is obsolete, do not use

#define SAP_BEGIN_SCHEMA_OBJECT(classname, sapclassname, clsid, iid, desc, sapversion, sapsystem, flags) \
CSapSchemaObject classname::ms_objSchema = {(wchar_t*)0, L#classname, L#sapclassname, &clsid, &iid, desc, L#sapversion, L#sapsystem, flags}; \
CSapSchemaVerb classname::ms_verbSchema[] = {

#define SAP_BEGIN_SCHEMA_OBJECT_1(classname, coclassname, sapclassname, clsid, iid, desc, sapversion, sapsystem, flags) \
CSapSchemaObject classname::ms_objSchema = {coclassname, L#classname, sapclassname, &clsid, &iid, desc, sapversion, sapsystem, flags}; \
CSapSchemaVerb classname::ms_verbSchema[] = {

#define SAP_END_SCHEMA_OBJECT \
{SAP_ID_SCHEMA_END, NULL, NULL, 0, NULL, VT_EMPTY, RFCTYPE_NULL, NULL, 0, 0, 0} \
};

#define SAP_END_SCHEMA_OBJECT_1 \
{SAP_ID_SCHEMA_END, NULL, NULL, 0, NULL, VT_EMPTY, RFCTYPE_NULL, NULL, 0, 0, 0} \
};

#define SAP_SCHEMA_METHOD(name, abapname, dispid, desc, flags) \
	{SAP_ID_SCHEMA_METHOD, L#name, L#abapname, dispid, desc, VT_EMPTY, RFCTYPE_NULL, L"", (CAnyAbapType*)0, 0, 0, flags},

#define SAP_SCHEMA_PARAMETER(name, abapname, desc, oletype, rfctype, length, decimals, flags) \
	{SAP_ID_SCHEMA_PARAMETER, L#name, L#abapname, 0, desc, oletype, rfctype, L"", (CAnyAbapType*)0, length, decimals, SAP_ID_SCHEMA_SCALAR | (flags) },

#define SAP_SCHEMA_PARAMETER_STRUCT(name, abapname, desc, oletype, rfctype, refstruct, flags) \
	{SAP_ID_SCHEMA_PARAMETER, L#name, L#abapname, 0, desc, oletype, rfctype, L#refstruct, &refstruct ## _Type, 0,0,flags},

#define SAP_SCHEMA_PARAMETER_STRUCT_1(name, abapname, desc, oletype, rfctype, refstruct, refstructnorm, flags) \
	{SAP_ID_SCHEMA_PARAMETER, L#name, L#abapname, 0, desc, oletype, rfctype, L#refstruct, &refstructnorm ## _Type, 0,0,flags},

#define SAP_SCHEMA_EXCEPTION(name) \
	{SAP_ID_SCHEMA_EXCEPTION, L#name, NULL, 0, NULL, VT_EMPTY, RFCTYPE_CHAR, L"", (CAnyAbapType*)0, 0, 0, 0 },

#define SAP_SCHEMA_KEY(name, dispid, desc, oletype, rfctype, length, decimals) \
	{SAP_ID_SCHEMA_KEY, L#name, L"", dispid, desc, oletype, rfctype, L"", (CAnyAbapType*)0, length, decimals, SAP_ID_SCHEMA_SCALAR},

#define DECLARE_SAP_SCHEMA_OBJECT \
public: \
static CSapSchemaObject ms_objSchema; \
static CSapSchemaVerb ms_verbSchema[]; \
static CSapSchemaObject * getObjSchema() \
{   if( (wchar_t*)0 == ms_objSchema.Name )\
    { LPOLESTR pProgId = NULL;                  \
      ProgIDFromCLSID( *GetCLSID(), &pProgId ); \
      if( pProgId != NULL )                     \
                   ms_objSchema.Name = pProgId; \
    };                                   \
    return &ms_objSchema;                \
}                                        \
virtual HRESULT GetSchema( CSapSchemaObject ** pObjSchema, CSapSchemaVerb ** pverbSchema ) \
{ *pObjSchema = getObjSchema(); *pverbSchema = ms_verbSchema; return S_OK; }

#define COM_INTERFACE_ALL_SAP_ENTRIES   COM_INTERFACE_ENTRY(ISupportErrorInfo) \
					COM_INTERFACE_ENTRY( ISAPConnector )   \
                    COM_INTERFACE_ENTRY( ISAPCatalog )     \
					COM_INTERFACE_ENTRY(ISAPrfcBind)

#define COM_INTERFACE_ALL_SAP_TRFC_ENTRIES   COM_INTERFACE_ENTRY(ISupportErrorInfo) \
					COM_INTERFACE_ENTRY( ISAPTRfcConnector )   \
                    COM_INTERFACE_ENTRY( ISAPCatalog )     \
					COM_INTERFACE_ENTRY(ISAPrfcBind)

#define COM_INTERFACE_ALL_SAP_QRFC_ENTRIES   COM_INTERFACE_ENTRY(ISupportErrorInfo) \
					COM_INTERFACE_ENTRY( ISAPQRfcConnector )   \
                    COM_INTERFACE_ENTRY( ISAPCatalog )     \
					COM_INTERFACE_ENTRY(ISAPrfcBind)

#define COM_INTERFACE_ALL_SAP_BASE_PROXY   COM_INTERFACE_ENTRY(ISupportErrorInfo) \
				   COM_INTERFACE_ENTRY( ISAPrfcBind ) 

//
// internal tables and type templates
//
#include <oledb.h>
#include "sapirfc.h" 
//
// @class Class for a dynamic ABAP Type Description 
// in an MTS environment (no type checking).
// 
//
class CAnyAbapType
{
public:
    // @cmember constructor needs type name and type description
    CAnyAbapType( const char * typeName, const RFC_TYPE_ELEMENT * typedescr, unsigned entries, const GUID& id = GUID_NULL )
                : m_Static( 0 )
    {
        Init( typeName, typedescr, entries, id );
    }

    CAnyAbapType() : m_Static( 0 ), m_typeName( NULL ), m_typeDescr( NULL ), m_typeEntries( 0 )
    {}

    ~CAnyAbapType()
    {
        ReleaseStatic();
    }

private:
    void Init( const char * typeName, const RFC_TYPE_ELEMENT * typedescr, unsigned entries, 
               const GUID& id = GUID_NULL)
    {
        m_typeEntries = entries;
        m_typeName    = typeName;
        m_typeDescr   = typedescr;
        if( id == GUID_NULL )
        {
            CoCreateGuid( &m_id );
        }
        else
            m_id = id;
    }

    void ReleaseStatic()
    {
        
	try
	{
	   m_iSAPrfcStructDesc.Release();
	}
	catch( ... )
	{
           m_iSAPrfcStructDesc.p = NULL;
	}

        return;
    }

    void checkInstalled()
    {
        CSapController c(g_szSAPMTX_H);

        if( FALSE == !m_iSAPrfcStructDesc )
            return;
        USES_CONVERSION;
        CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc;
        CoCreateInstance(CLSID_CSAPrfcStructDesc, 
		         0,
		         CLSCTX_SERVER,
		         IID_ISAPrfcStructDesc,
		         (void**)&iSAPrfcStructDesc) 
                         >> XLine(c);

        iSAPrfcStructDesc->SetName( A2OLE( m_typeName ) ) >> XLine(c); 
        iSAPrfcStructDesc->SetGuid( &m_id ) >> XLine(c);
        for ( unsigned i=0; i < m_typeEntries; i++ )
        {
            iSAPrfcStructDesc->AddField( 
                                  A2OLE((char*)m_typeDescr[i].name), /*TODO: unti SAP_UC*/
                                  m_typeDescr[i].type,
                                  m_typeDescr[i].length,
                                  m_typeDescr[i].decimals,
                                  0) 
                                  >> XLine(c);
        }
        iSAPrfcStructDesc->Lock() >> XLine(c);
        m_iSAPrfcStructDesc = iSAPrfcStructDesc;
        if( 0 != m_Static )
        {
            // make sure that static COM refences don't get deleted
            m_iSAPrfcStructDesc.p->AddRef();
        }
        return;
    }

public: // must only be used by CAbapType< T >
    void InitStatic( const char * typeName, const RFC_TYPE_ELEMENT * typedescr, unsigned entries, const GUID& id = GUID_NULL)
    {   
        Init( typeName, typedescr, entries, id );
        m_Static = 1;
    }

private:
    CComPtr< ISAPrfcStructDesc > m_iSAPrfcStructDesc;
    int                          m_Static;
    const char *                 m_typeName;
    const RFC_TYPE_ELEMENT *     m_typeDescr;
    unsigned                     m_typeEntries;
    GUID                         m_id;

public:
    // @cmember get the type handle for <t RFC_PARAMETER>
    RFC_TYPEHANDLE getType()     
    {
        RFC_TYPEHANDLE hType;
        CSapController c(g_szSAPMTX_H);
        checkInstalled();
        CComQIPtr< ISAPrfcStructHandleAccess, &IID_ISAPrfcStructHandleAccess > GoNative = 
                                   ( ISAPrfcStructDesc *) m_iSAPrfcStructDesc;
        if( !GoNative )
        {
            E_NOINTERFACE >> XLine(c);
        }
        GoNative->GetHandle( &hType ) >> XLine(c);
        return hType;
    }

    // @cmember get the type description
    void getTypeDescription( const RFC_TYPE_ELEMENT ** ppDescription, unsigned * pEntries )
    {
        *ppDescription = m_typeDescr;
        *pEntries      = m_typeEntries;
        return;
    }

    // @cmember get the type's name
    const char * getTypeName()
    {
        return m_typeName;
    }

    // @cmember get the type description as COM object 
    HRESULT getISAPrfcStructDesc(ISAPrfcStructDesc ** ppISAPrfcStructDesc )
    {
        ISAPrfcStructDesc * pISAPrfcStructDesc;
        checkInstalled();
        pISAPrfcStructDesc =  ( ISAPrfcStructDesc * ) m_iSAPrfcStructDesc;
        pISAPrfcStructDesc->AddRef();
        *ppISAPrfcStructDesc = pISAPrfcStructDesc;
        return S_OK;
    }
};

// @class Template class for an ABAP Type Description 
// in an MTS environment.
// 
// Generating a C structure with the genh
// utility or with the RFC interface generator in 
// the ABAP repository (Transaction SE80 or SE37)
// results in a C structure and a structure description
// of type <t RFC_TYPE_ELEMENT>.
//
// These two parts must be used to create a type
// description object. 
//
// A type description object is created
// in static or global scope using a generated header
// containing the structure definition
//
// @base  public | CAnyAbapType
// @tcarg class | T | The ABAP type as a C structure
//
//
// @ex Assume we have a header file t100.h for the
// structure T100 in R/3 generated by SE37 or genh |
// 
// #define RFC_DEFINE_STRUCTURE /* generate the structure description */
// #include "t100.h"
//
// /* the type object must be defined with global scope */ 
// CAbapType< T100 > t100_type ( "T100", 
//                               Description_T100,  /* from t100.h */
//                               ENTRIES_OF_T100 ); /* from t100.h */
//
// @comm Defining also RFC_DEFINE_TYPE a genh generated header
// declares the type description automatically. 
//
// @xref <t CAnyAbapType>
//
template <class T>
class CAbapType : public CAnyAbapType 
{
public:
    CAbapType( const char * typeName, const RFC_TYPE_ELEMENT * typedescr, unsigned entries, const GUID& id = GUID_NULL )
    {
        CAnyAbapType::InitStatic( typeName, typedescr, entries, id );
    }

private:
    CAbapType()
    {
    }
    
};


//
// @class Template class for a general ABAP internal table 
// in an MTS environment (no type checking on row types).
// 
// @tcarg class | TYPECLASS | The class describing a row 
//
template <class TYPECLASS>
class CAnyAbapTable
{
    public:
        // @cmember constructor needs the type object
        CAnyAbapTable( TYPECLASS * pType )
        {
            m_pType = pType;
        }

        ~CAnyAbapTable()
        {
            // forget m_pType simply
        }

    protected:
        TYPECLASS            * m_pType;
        CComPtr< ISAPrfcITab > m_ISAPrfcITab;
    
    public:
     // @cmember get the table as <t ITAB_H>.
     ITAB_H getITAB_H()
     {
         ITAB_H                             pItab         = ITAB_NULL;
         CComPtr< ISAPrfcITabHandleAccess > pNativeAccess;
         CComPtr< ISAPrfcITab >             pISAPrfcITab;
         getISAPrfcITab( &pISAPrfcITab );
         if( FALSE == !pISAPrfcITab )
         {
             CComQIPtr< ISAPrfcITabHandleAccess, &IID_ISAPrfcITabHandleAccess > 
                                                         pNativeAccess = pISAPrfcITab;

             if( FALSE == !pNativeAccess )
             {
                  pNativeAccess->GetHandle(&pItab);
             }
         }
         return pItab;
     }

     // @cmember get the row type of a table.
     RFC_TYPEHANDLE getType()     
     {
         if( m_pType != NULL )
             return m_pType->getType();
         else
             return RFCTYPE_NULL;
     }

     // @cmember get the row type as COM object.
     HRESULT getISAPrfcStructDesc( ISAPrfcStructDesc ** ppISAPrfcStructDesc )
     {
         if( NULL == m_pType )
             return E_FAIL;
         return m_pType->getISAPrfcStructDesc( ppISAPrfcStructDesc );
     }

     // @cmember get the row type's name
     const char * getTypeName()
     {
         if( NULL == m_pType )
             return NULL;
         else
             return m_pType->getTypeName();
     }

     // @cmember get the table as COM object (SAP interface)
     HRESULT getISAPrfcITab( ISAPrfcITab ** ppISAPrfcITab )
     {
         HRESULT                      hr           = S_OK;
         CComPtr< ISAPrfcITab >       pISAPrfcITab;
         CComPtr< ISAPrfcStructDesc > pStructure;
         *ppISAPrfcITab = NULL;
         if( !m_ISAPrfcITab )
         {
             const char        * name         = getTypeName(); 
       	     getISAPrfcStructDesc( &pStructure );
             if( NULL == name || !pStructure )
                    goto error;
             USES_CONVERSION;
		     hr = CoCreateInstance( CLSID_CSAPrfcITab, 0,
				    CLSCTX_SERVER,
				    IID_ISAPrfcITab,
				    (void**)&pISAPrfcITab );
	     if( FAILED(hr) ) 
			goto error;
             hr = pISAPrfcITab->CreateStructured( A2OLE( name ), 
                                                  pStructure );
             if( FAILED(hr) )
                 goto error;
             // move pointer to member var.
             m_ISAPrfcITab = pISAPrfcITab;
         }
         goto end;
error:
         return AtlReportError(CLSID_CSAPrfcITab, 
                               "Cannot create ITab COM Wraper.", 
                               IID_ISAPrfcITab, 
                               hr 
                              );
 
end:
         if( FALSE == !m_ISAPrfcITab )
                m_ISAPrfcITab.p->AddRef();
         *ppISAPrfcITab = (ISAPrfcITab *) m_ISAPrfcITab;
         return S_OK;
     }

     // @cmember get the table as OLE DB Rowset
     HRESULT getIRowset( IRowset   ** ppIRowset)
     {
         CComPtr< ISAPrfcITab >            pISAPrfcITab;
         CComQIPtr<IRowset, &IID_IRowset > pIRowset;
         getISAPrfcITab( &pISAPrfcITab );
         pIRowset = pISAPrfcITab;
         if( FALSE == !pIRowset ) 
                pIRowset.p->AddRef();
         *ppIRowset = pIRowset;
         return (!pIRowset) ? E_FAIL : S_OK;
     }

     // @cmember get the table as marshalable RDS/ADO Recordset
     HRESULT getRDSRecordSet( IDispatch ** ppIDispatch )
     {
         DWORD   prop = IRFCPROP_IMPORT | IRFCPROP_EXPORT | IRFCPROP_CACHED;
         return getRecordSet( prop, ppIDispatch ); 
     }

     // @cmember get the table as  local ADO Recordset
     HRESULT getLocalRecordSet( IDispatch ** ppIDispatch )
     {
         DWORD   prop = IRFCPROP_LOCAL;
         return getRecordSet( prop, ppIDispatch ); 
     }

     // @cmember copy a Recordset into the table
     HRESULT PopulateFromRecordSet( IDispatch * pIDispatch )
     {
         return copyFromRecordSet( pIDispatch );
     }

     // @cmember get offset and field description of a table field (ABAP representation)
     HRESULT GetStructureField( OLECHAR         * colName, unsigned long   * pOffset, unsigned long   * pLeng, unsigned long   * pDecimals, RFC_TYPEHANDLE  * pRfcTypeHandle )
     {
         CSapController c(g_szSAPMTX_H);
         CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc;
         try
         {
            int found = 0;
            getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
            for( int i = 0; ;i++ )
            {
                OLECHAR wszName[128];
                CComPtr<ISAPrfcStructDesc> fieldStructDesc1;
                fieldStructDesc1.Release();
                iSAPrfcStructDesc->GetField( i, wszName, sizeof(wszName), 
                                             pRfcTypeHandle, 
                                             pLeng, 
                                             pDecimals, 
                                             pOffset, 
                                             &fieldStructDesc1) >> XLine(c);
                if( wcscmp( wszName, colName ) == 0 )
                {
                    found = 1;
                    break;
                }
            }
         }
         catch( HRESULT hr )
         {
             return hr;
         }
         return S_OK;
     }

     HRESULT GetStructureField( unsigned int columnNumber, unsigned long   * pOffset, unsigned long   * pLeng, unsigned long   * pDecimals, RFC_TYPEHANDLE  * pRfcTypeHandle, OLECHAR * pName, size_t maxNameSize )
     {
         CSapController c(g_szSAPMTX_H);
         CComPtr< ISAPrfcStructDesc > iSAPrfcStructDesc;
         try
         {
            getISAPrfcStructDesc( &iSAPrfcStructDesc ) >> XLine(c);
            CComPtr<ISAPrfcStructDesc> fieldStructDesc1;
            iSAPrfcStructDesc->GetField( (int) columnNumber, 
                                          pName, maxNameSize, 
                                          pRfcTypeHandle, 
                                          pLeng, 
                                          pDecimals, 
                                          pOffset, 
                                          &fieldStructDesc1) >> XLine(c);

         }
         catch( HRESULT hr )
         {
             return hr;
         }
         return S_OK;
     }


private:
     HRESULT getRecordSet( DWORD prop, IDispatch ** ppIDispatch )
     {
         HRESULT hr;
         CComQIPtr< ISAPrfcITab2Recordset, &IID_ISAPrfcITab2Recordset > iSAPrfcITab2Recordset;
         CComPtr< ISAPrfcITab > pISAPrfcITab;
         CComPtr< IDispatch >   recordSet;
         getISAPrfcITab( &pISAPrfcITab );
         iSAPrfcITab2Recordset = pISAPrfcITab;
         if( !iSAPrfcITab2Recordset )
                    return E_NOINTERFACE;
         hr = iSAPrfcITab2Recordset->GetRecordset( prop, &recordSet );
         if( FAILED( hr ) ) 
             return hr;
         recordSet.p->AddRef();
         *ppIDispatch = recordSet;
         return S_OK;
     }

private:
     HRESULT copyFromRecordSet( IDispatch * pIDispatch )
     {
        CSapController c(g_szSAPMTX_H);
        CComQIPtr< ISAPrfcITab2Recordset, &IID_ISAPrfcITab2Recordset > iSAPrfcITab2Recordset;
        CComPtr< ISAPrfcITab > iSAPrfcITab;
        try
        {
            getISAPrfcITab( &iSAPrfcITab ) >> XLine(c);
            iSAPrfcITab2Recordset = iSAPrfcITab;
            if( !iSAPrfcITab2Recordset )
                             E_NOINTERFACE >> XLine(c);
            iSAPrfcITab2Recordset->UpdateFromRecordset( 
                        IRFCPROP_IMPORT, 
                        pIDispatch ) >> XLine(c);
        }
        catch( HRESULT hr )
        {
            return hr;
        }
        return S_OK;
     }

};

// @class Template class for an ABAP internal table 
// in an MTS environment.
// 
// This class allows presenting an ABAP internal table
// as a <t ITAB_H> handle but also as an OLE DB Rowset as well
// as an ADO Recordset.
//
// @tcarg class | T | The ABAP type of a row as a 
// C structure
// @base public | CAnyAbapTable<LT>CAbapType<LT> T <GT><GT>
//
// @comm
// OLEDB SDK and ADO SDK must be installed to use thos class.
//
// @ex Assume we have a header file t100.h for the
// structure T100 and a corresponding type object. You can create
// an (empty) table by: | 
// 
// #define RFC_DEFINE_STRUCTURE /* generate the structure description */
// #include "t100.h"
//
// typedef CAbapType< T100 >  T100_TYPE; /* makes the code readable */
//
// /* the type object with static scope */ 
// static T100_TYPE t100_type ( "T100", 
//                               Description_T100,  /* from t100.h */
//                               ENTRIES_OF_T100 ); /* from t100.h */
//
//
// typedef CAbapTable< T100 > T100_TABLE;
//
// voif func( .... )
// {
//      T100_TABLE t100_table ( &t100_type );
//      ...     
//
//
// @xref <t CAnyAbapTable>, <t CAbapType>, <t CAnyAbapType>
template <class T> class CAbapTable : public CAnyAbapTable< CAbapType< T > >
{
    public:
    CAbapTable( CAbapType< T > * pType ) 
        : CAnyAbapTable< CAbapType< T > >( pType )
    {
    }

    private:
    HRESULT checkISAPrfcITAB()
    {
        if( ! m_ISAPrfcITab )
        {
            CComPtr< ISAPrfcITab > ptr;
            getISAPrfcITab( &ptr );
            return ( !ptr ) ?  E_FAIL : S_OK;
        }
        else 
            return S_OK;
    }

    public:
    // @cmember get a row of a table    
    HRESULT ReadLine( unsigned long line, T * dest )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->ReadLine( line, sizeof( T ), (byte *) dest );
    }
    // @cmember update a row of a table  
    HRESULT WriteLine( unsigned long line, T * src )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->WriteLine( line, sizeof( T ), (byte *) src );
    }
    // @cmember insert a new row into a table 
    HRESULT InsertLine( unsigned long line, T * src )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->InsertLine( line, sizeof( T ), (byte *) src );
    }

    // @cmember append a new row to a table 
    HRESULT AppendLine( T * src )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->AppendLine( sizeof( T ), (byte *) src );
    }

    // @cmember delete a row from a table 
    HRESULT DeleteLine( unsigned long line )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->DeleteLine( line );
    }
    // @cmember delete all rows from a table     
    HRESULT FreeLines( )
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->FreeLines();
    }

    // @cmember returns the number or rows     
    HRESULT get_LineCount( unsigned long  * plLines)
    {
        if( S_OK != checkISAPrfcITAB() )
            return E_FAIL;
        return m_ISAPrfcITab->get_LineCount( plLines );
    }

private:
     enum VIEW_FILTER_COMPARE
     {
         VIEW_FILTER_NEVER_TRUE    = 0, 
         VIEW_FILTER_COMPARE_EQUAL = 1,
         VIEW_FILTER_COMPARE_LIKE  = 2 
     };

     struct VIEW_FILTER_CONDITION
     {
         wchar_t      *         value;
         unsigned long          offset;
         unsigned long          length;
         unsigned long          decimals;
         RFC_TYPEHANDLE         rfcTypeHandle;
         VIEW_FILTER_COMPARE    compareFlags;
         unsigned int           asterixOffset;
     };

public:
     HRESULT getViewWhereKeyFieldsLike( /* in */  wchar_t ** pKeys, unsigned keyCount, 
                                        /* out */ CAbapTable<T> * pViewTable )
     {
         OLECHAR wBuffer[128];
         const unsigned conditionMax = keyCount;
         const int MAX_VIEW_FILTER_CONDITIONS = 128;
         VIEW_FILTER_CONDITION cond[MAX_VIEW_FILTER_CONDITIONS];
         try
         {
             // build up filter conditions
             for( unsigned i = 0; i < conditionMax && i < MAX_VIEW_FILTER_CONDITIONS; i++ )
             {
                 cond[i].value  = pKeys[i];
                 GetStructureField( i, &cond[i].offset, &cond[i].length,  
                                    &cond[i].decimals, &cond[i].rfcTypeHandle,
                                    wBuffer, (size_t) sizeof( wBuffer ) );
                 const wchar_t    * wcp = wcschr( pKeys[i], L'*' );
                 cond[i].asterixOffset  = (wcp == NULL) ? 
                                            0 : 
                                            (wcp - pKeys[i]);
                 if( cond[i].asterixOffset > cond[i].length )
                    cond[i].compareFlags = VIEW_FILTER_NEVER_TRUE; 
                 else
                    cond[i].compareFlags   = (wcp == NULL) ? 
                                               VIEW_FILTER_COMPARE_EQUAL : 
                                               VIEW_FILTER_COMPARE_LIKE;
             }
             pViewTable->FreeLines();
             for(  unsigned j = 1; ; j++ )
             {
                 T bufferOfT;
                 HRESULT hr = ReadLine( j, &bufferOfT );
                 if( FAILED( hr ) )
                       break;
                 if( true == viewCheckRow( &bufferOfT, cond, conditionMax ) )
                 {
                    pViewTable->AppendLine( &bufferOfT );
                 }
             }
         }
         catch( HRESULT hr )
         {
             return hr;
         }
         return S_OK;
     }

private:

    bool viewCompareField( wchar_t * pField, VIEW_FILTER_CONDITION * pKey, unsigned keyCount );
    bool viewCompareField( char * pField, VIEW_FILTER_CONDITION * pKey, unsigned keyCount );
    bool viewCheckRow( T * pRow, VIEW_FILTER_CONDITION * pKeys, unsigned keyCount );
};

template <class T>
bool  CAbapTable< T >::viewCompareField( wchar_t * pField, VIEW_FILTER_CONDITION * pKey, unsigned keyCount )
{
    wchar_t   space = L' ';
    wchar_t * p2 = pKey->value;
    wchar_t * pFieldEnd;
    if( pKey->compareFlags == VIEW_FILTER_NEVER_TRUE )
        return false;
    if( pKey->compareFlags == VIEW_FILTER_COMPARE_LIKE )
        pFieldEnd = (wchar_t *)((char *) pField + pKey->asterixOffset );
    else
        pFieldEnd = (wchar_t *)((char *) pField + pKey->length );
    for( ; pField < pFieldEnd; pField++ )
    {
        if( *p2 == 0 )
            p2 = &space;
        if( *p2 != *pField )
            return false;
        if( p2 != &space )
            p2++;
    }
    return true;
}

template <class T>
bool  CAbapTable< T >::viewCompareField( char * pField, VIEW_FILTER_CONDITION * pKey, unsigned keyCount )
{
    USES_CONVERSION;
    char   space = ' ';
    char * p2 = W2A( pKey->value );
    char * pFieldEnd;
    if( pKey->compareFlags == VIEW_FILTER_NEVER_TRUE )
        return false;
    if( pKey->compareFlags == VIEW_FILTER_COMPARE_LIKE )
        pFieldEnd = (char *)((char *) pField + pKey->asterixOffset );
    else
        pFieldEnd = (char *)((char *) pField + pKey->length );
    for( ; pField < pFieldEnd; pField++ )
    {
        if( *p2 == 0 )
            p2 = &space;
        if( *p2 != *pField )
            return false;
        if( p2 != &space )
            p2++;
    }
    return true;
}

template <class T>
bool  CAbapTable< T >::viewCheckRow( T * pRow, VIEW_FILTER_CONDITION * pKeys, unsigned keyCount )
{
    VIEW_FILTER_CONDITION * pKey;
    for( unsigned i = 0; i < keyCount; i++ )
    {
        pKey = & pKeys[i];
        switch( pKey->rfcTypeHandle )
        {
        default:
            break;
        case RFCTYPE_DATE:
        case RFCTYPE_TIME:
        case RFCTYPE_NUM:
        case RFCTYPE_CHAR:
            {
                char * pField = (char *)((char *) pRow + pKey->offset);

                if( true != viewCompareField( pField, pKey, keyCount ) )
                {
                    return false;
                }
            }
            break;
        case RFCTYPE_WIDE_2:
            {
                wchar_t * pField = (wchar_t *)((char *) pRow + pKey->offset);
                if( true != viewCompareField( pField, pKey, keyCount ) )
                {
                    return false;
                }
            }
            break;
        }
    }
    return true;
}


//
// some macros easing the use of these template classes
// in code generators.
//
// The data type of an ABAP table containing a row type
#define ABAP_TABLE( RowType ) RowType ## _TABLE
//
// declaration of a ABAP table type
// should be placed into global scope
//
#define DECLARE_TYPE_ABAP_TABLE( RowType )              \
   typedef CAbapType< RowType > RowType ## _TYPE;       \
   static RowType ## _TYPE RowType ## _Type ( # RowType, \
        Description_ ## RowType ,                        \
        ENTRIES_OF_ ## RowType );                        \
   typedef CAbapTable< RowType > ABAP_TABLE( RowType ) /* no ; */
 
// 
// extern declaration
//
#define DECLARE_EXTERN_TYPE_ABAP_TABLE( RowType )              \
   typedef CAbapType< RowType > RowType ## _TYPE;              \
   extern RowType ## _TYPE RowType ## _Type;                    \
   typedef CAbapTable< RowType > ABAP_TABLE( RowType ) /* no ; */
 
#define DEFINE_GLOBAL_TYPE_ABAP_TABLE( RowType )               \
        RowType ## _TYPE RowType ## _Type ( # RowType,          \
        Description_ ## RowType ,                               \
        ENTRIES_OF_ ## RowType );                               \

//
// definition of a table
// 
#define DEFINE_ABAP_TABLE( TAB, name ) \
	TAB ## _TABLE name (& TAB ## _Type )

#endif /* __midl */
#endif /* c++ */
#endif /* SAPMTX_H */

/* GUIDs and global/static data */
#ifdef SAPMTX_GLOBAL
#ifdef SAPMTX_DEFINE_GUIDS 
#ifndef SAPIRFC_I_C
#include "sapirfci.c"
#define SAPIRFC_I_C
#endif
#endif

void    CRfcResourceDispenser::_CleanUpForLeakTest()
{
    if( NULL != m_pISAPrfcContextSource )
    {
	m_pISAPrfcContextSource->Close();
        m_pISAPrfcContextSource->Release();
        m_pISAPrfcContextSource = NULL;
    }
    return;
}

void    CRfcResourceDispenser::ErrorReset()
{
    CComPtr< IErrorInfo > iErrorInfo;
    GetErrorInfo( 0, &iErrorInfo );
    iErrorInfo.Release();
    return;
}

void    CRfcResourceDispenser::Trace( _TCHAR * entryPoint, _TCHAR * fname, int line, _TCHAR * text, HRESULT hr )
{
#ifdef SAPMTX_TRACE_ON
    CComPtr< ISAPrfcContextSource > iSAPrfcContextSource;
    GetContextSource( &iSAPrfcContextSource );
    if( !!iSAPrfcContextSource )
    {
#ifdef SAPwithUNICODE
        CComQIPtr< ISAPrfcTraceU, &IID_ISAPrfcTrace > iSAPrfcTrace (iSAPrfcContextSource);
#else
		CComQIPtr< ISAPrfcTrace, &IID_ISAPrfcTraceU > iSAPrfcTrace (iSAPrfcContextSource);
#endif
        if( !!iSAPrfcTrace )
        {
            if( hr == S_OK )
            {
              iSAPrfcTrace->Trace( entryPoint, 
                                   fname, line, 
                                   text 
                                 );
            }
            else
            {
              iSAPrfcTrace->OnError( entryPoint, 
                                     fname, line, 
                                     text, 
                                     hr 
                                   );
            }
        }
    }
#endif
    return;
}


HRESULT CRfcResourceDispenser::OnError( _TCHAR * entryPoint, _TCHAR * fname, int line, _TCHAR * text, HRESULT hResult )
{
    if( SUCCEEDED( hResult ) )
        return hResult;
    CComPtr< ISAPrfcContextSource > iSAPrfcContextSource;
    GetContextSource( &iSAPrfcContextSource );
    if( !!iSAPrfcContextSource )
    {
#ifdef SAPwithUNICODE
        CComQIPtr< ISAPrfcTraceU, &IID_ISAPrfcTraceU > iSAPrfcTrace (iSAPrfcContextSource);
#else
        CComQIPtr< ISAPrfcTrace, &IID_ISAPrfcTrace > iSAPrfcTrace (iSAPrfcContextSource);
#endif
        if( !!iSAPrfcTrace )
        {
            iSAPrfcTrace->OnError( 
#ifdef SAPwithUNICODE
                                   entryPoint, 
                                   fname, line, 
                                   text, 
#else
                                   (SAP_RAW*)entryPoint,  //TODO
                                   (SAP_RAW*)fname, line, 
                                   (SAP_RAW*)text, 
#endif
                                   hResult );
        }
    }
    return hResult;
}

// static function to create Resource Dispenser */
HRESULT CRfcResourceDispenser::GetContextSource( ISAPrfcContextSource ** ppISAPrfcContextSource )
{
    if( NULL == m_pISAPrfcContextSource)
    {
        HRESULT hr;
        hr = GetFirstContextSource(ppISAPrfcContextSource );
        return hr;
    }
    *ppISAPrfcContextSource = (ISAPrfcContextSource *) m_pISAPrfcContextSource;
    (*ppISAPrfcContextSource)->AddRef();
    return S_OK;
}

HRESULT CRfcResourceDispenser::GetFirstContextSource( ISAPrfcContextSource ** ppISAPrfcContextSource )
{
    //use CS only first the first allocation
    m_cs.Lock();
    if( NULL == m_pISAPrfcContextSource)
    {
        HRESULT hr;
        hr = CoCreateInstance(CLSID_RfcContextSource, 
		              0,
		              CLSCTX_INPROC_SERVER,
		              IID_ISAPrfcContextSource,
		              (void **) &m_pISAPrfcContextSource );
        if( FAILED( hr ) )
        {
            hr = AtlReportError( CLSID_RfcContextSource, 
                                 "Cannot create RFC Resource Dispenser.", 
                                 IID_ISAPrfcContextSource, 
                                 hr );
            m_cs.Unlock();
            return hr;
        }
        // Never release this Reference
        // because the DLLs are unloaded before the destructor
        //
        m_pISAPrfcContextSource->AddRef();
    }
    m_cs.Unlock();
    *ppISAPrfcContextSource = (ISAPrfcContextSource *) m_pISAPrfcContextSource;
    (*ppISAPrfcContextSource)->AddRef();
    return S_OK;
}

CAbapScalarType::CAbapScalarType( RFCTYPE rfctype, unsigned bytes, unsigned decimals )
{
    m_ScalarType._size     = sizeof( m_ScalarType ); 
    m_ScalarType.rfctype   = rfctype;
    m_ScalarType.decimals  = decimals;
    if( 0 == bytes )
    {
        switch( rfctype )
        {
        case RFCTYPE_INT:
            bytes = sizeof( RFC_INT );
            break;
        case RFCTYPE_FLOAT:
            bytes = sizeof( RFC_FLOAT );
            break;
        case RFCTYPE_DATE:
            bytes = sizeof( RFC_DATE );
            break;
        case RFCTYPE_TIME:
            bytes = sizeof( RFC_TIME );
            break;
        case RFCTYPE_INT2:
            bytes = sizeof( RFC_INT2 );
            break;
        case RFCTYPE_INT1:
            bytes = sizeof( RFC_INT1 );
            break;
        case RFCTYPE_IUNKNOWN:
            bytes = sizeof( IUnknown * );
            break;
        default:
            break;
        }
    }
    m_ScalarType.bytes     = bytes;
}

#include <time.h>

HRESULT CSapRegistryHelper::SapSpecialUpdateRegistryEx(UINT nResID, SapConnectorRegistryEntry * registryEntries, BOOL update )
{
	USES_CONVERSION;
	CSapController c(g_szSAPMTX_H);
	long    rc;
	CRegKey regKey;
	TCHAR   buffer[256];
	DWORD   dwCount(256);
	OLECHAR wbuffer2[64];
	OLECHAR wbufferClassId[64];
	CComBSTR bstr;
	HRESULT hr(S_OK);
	try
	{
		TCHAR   * ptSchema       = NULL;
		TCHAR   * componentsPath = _T("Software\\SAP\\MTS\\Components");
		TCHAR   * schemaPath     = _T("Software\\SAP\\MTS\\Schema");
		const TCHAR * szProgId = NULL;
		StringFromGUID2( *m_pclsid, wbufferClassId, 64 );
		_stprintf( buffer, _T("%s\\%s"), componentsPath, OLE2T( wbufferClassId) ); 
		if( TRUE == update )
		{
            LPOLESTR pProgId = NULL;
			//register
			hr = _Module.UpdateRegistryFromResource(nResID, update);
			if( FAILED(hr) )
				hr >> XLine(c);
			rc = regKey.Create( HKEY_LOCAL_MACHINE,  buffer  );
			if( ERROR_SUCCESS != rc )
				E_FAIL >> XLine(c);
			if( SUCCEEDED( ProgIDFromCLSID( *m_pclsid, &pProgId ) ))
			{
				szProgId = OLE2CT(pProgId);
				(void) regKey.SetKeyValue( _T( "Progid" ), szProgId );
			}
			//Address of output variable that receives a 
			// pointer to the requested ProgID string);
			if( m_piid != NULL )
			{
				StringFromGUID2( *m_piid, wbuffer2, 64 );
				rc = regKey.SetKeyValue( _T("Interface"),
										 W2CT(wbuffer2) );
				if( ERROR_SUCCESS != rc )
					E_FAIL >> XLine(c);
			}
            if( m_plibid != NULL )
            {
                StringFromGUID2( *m_plibid, wbuffer2, 64 );
                rc = regKey.SetKeyValue( _T("Library"),
						                 W2CT(wbuffer2) );
                if( ERROR_SUCCESS != rc )
		                E_FAIL >> XLine(c);
            }
            if( NULL != m_pObjSchema && NULL != m_pObjSchema->sapsystem )
            {
                ptSchema = W2T(m_pObjSchema->sapsystem);
            }
            else
            {
                ptSchema =  _T("CONNECTOR");
            }
            rc = regKey.SetKeyValue( _T("System" ), ptSchema );
	            if( ERROR_SUCCESS != rc )
		            E_FAIL >> XLine(c);
            time_t t = time( NULL );
            char acttime[64];
            strftime( acttime, sizeof(acttime), 
                      "%Y" "%m" "%d" "%H" "%M" "%s",
                      localtime( &t ) );
            rc = regKey.SetKeyValue( _T("InstallTime" ),
  					                 A2CT( acttime ) );
            if( ERROR_SUCCESS != rc )
		            E_FAIL >> XLine(c);
            rc = regKey.SetKeyValue( _T("CreateTime" ),
				                     A2CT( acttime ) );
            if( ERROR_SUCCESS != rc )
	            E_FAIL >> XLine(c);
            if( NULL != m_pObjSchema )
            {
                if( m_pObjSchema->Name != NULL )
                {
	                rc = regKey.SetKeyValue( _T("ClassName" ),
 							                 W2CT(m_pObjSchema->Name) );
	                if( ERROR_SUCCESS != rc )
				                E_FAIL >> XLine(c);
                }
								else 
								{
									(void) regKey.SetKeyValue( _T( "ClassName" ), szProgId );
                  m_pObjSchema->Name = pProgId;
								}
                if( m_pObjSchema->InternalName != NULL )
                {
	                rc = regKey.SetKeyValue( _T("AbapClassName" ),
			 				                 W2CT(m_pObjSchema->InternalName) );
	                if( ERROR_SUCCESS != rc )
				                E_FAIL >> XLine(c);
                }
                if( NULL != m_pObjSchema->Desc )
                {
	                rc = regKey.SetKeyValue( _T("Description" ),
									                 W2CT(m_pObjSchema->Desc ) );
		            if( ERROR_SUCCESS != rc )
			                E_FAIL >> XLine(c);
                }
            }
						else
						{
							(void) regKey.SetKeyValue( _T( "ClassName" ), szProgId );
						}
            for( int i = 0; registryEntries && registryEntries[i].id != (_TCHAR *) 0; i++ )
			{
				if( registryEntries[i].key == SR_System ) 
				{
					ptSchema = A2T( (char *) registryEntries[i].value );
				}
                switch( registryEntries[i].key )
                {
                case SR_PROGID:
                    registryEntries[i].id = _T("Progid");
                    break;
                case SR_INTERFACE:
                    registryEntries[i].id = _T("Interface");
                    break;
                case SR_InstallDate:
                    registryEntries[i].id = _T("InstallTime");
                    break;
                case SR_LIBRARY:
                    registryEntries[i].id = _T("Library");
                    break;
                case SR_PACKAGE:
                    registryEntries[i].id = _T("Package");
                    break;
                case SR_BOR_CLASSNAME:
                    registryEntries[i].id = _T("ClassName");
                    break;
                default:
                    break;
                }
				rc = regKey.SetKeyValue( registryEntries[i].id,
										 registryEntries[i].value );
				if( ERROR_SUCCESS != rc )
						 E_FAIL >> XLine(c);
			}
            if( NULL != ptSchema )
            {        
                _stprintf( buffer, _T("%s\\%s"), schemaPath,  ptSchema  ); 
                rc = regKey.Create( HKEY_LOCAL_MACHINE,  buffer  );
	            if( ERROR_SUCCESS != rc )
			                E_FAIL >> XLine(c);
                if( NULL != m_pObjSchema )
                {
	                if( m_pObjSchema->Name != NULL )
	                {
		                rc = regKey.SetKeyValue( W2CT(m_pObjSchema->Name),
	 							                   W2CT(wbufferClassId) );
  	                    if( ERROR_SUCCESS != rc )
			                E_FAIL >> XLine(c);
	                }
                    else
                    {
                            E_FAIL >> XLine( c );
                    }
                }
            }			
        }
        else
        {
			//unregister
			_TCHAR*    szTmp;
			_TCHAR     szKey[256];
			int      nVerCur, nVerThis;
			bool     bRebuild(false);
			CLSID    clsId;
			if(ERROR_SUCCESS == regKey.Open( HKEY_LOCAL_MACHINE, componentsPath ))
			{
				rc = regKey.RecurseDeleteKey( OLE2T( wbufferClassId) );
				if( ERROR_SUCCESS != rc )
					E_FAIL >> XLine(c);
			}
			//rebuild version independent ProgId if CurVer is newer than this version
			//no error if not found
            LPOLESTR pProgId = NULL;
			if( SUCCEEDED(ProgIDFromCLSID(*m_pclsid, &pProgId)) )
			{
                bstr = pProgId;
                if( pProgId != NULL )
                    CoTaskMemFree((void*) pProgId);
				_tcscpy(szKey, OLE2CT((BSTR)bstr));
				if( (szTmp = _tcsrchr(szKey, _T('.'))) != NULL )
				{
					nVerThis = _ttoi(szTmp+1);
					szTmp[0] = _T('\0'); 
					_tcscat(szKey, _T("\\CurVer"));
					if( (rc = regKey.Open(HKEY_CLASSES_ROOT, szKey, KEY_QUERY_VALUE)) == ERROR_SUCCESS )
					{
						if( (rc = regKey.QueryValue(buffer, NULL, &dwCount)) == ERROR_SUCCESS )
						{
							if( (szTmp = _tcsrchr(buffer, _T('.'))) != NULL )
							{
								nVerCur = _ttoi(szTmp+1);
								if( nVerCur > nVerThis )
									bRebuild = true;
								else
								{
									//check if lower version already exists
									szTmp[1] = _T('\0');
									while(--nVerCur > 0)
									{
										TCHAR buf[20];
										_itot(nVerCur, buf, 10);
										_tcscat(buffer, buf);
										if( SUCCEEDED(CLSIDFromProgID(T2COLE(buffer), &clsId)) )
										{
											dwCount = _tcslen(buffer)+1;
											bRebuild = true;
											break; 
										}
										else
										{
											if( (szTmp = _tcsrchr(buffer, _T('.'))) != NULL )
												szTmp[1] = _T('\0');
										}
									}
								}
							}
						}
					}
				}
			}
			hr = _Module.UpdateRegistryFromResource(nResID, update);
			if( FAILED(hr) )
				hr >> XLine(c);
			if( bRebuild )
			{
				DWORD dwDisp; 
		        HKEY  hKey = NULL; 
				//rebuild version independent ProgId entry in the registry
				if( (rc = RegCreateKeyEx( HKEY_CLASSES_ROOT, szKey, REG_NONE, NULL,REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY | KEY_SET_VALUE, NULL, &hKey, &dwDisp)) == ERROR_SUCCESS ) 
					rc = RegSetValueEx( hKey, NULL, NULL, REG_SZ, (LPBYTE)buffer, dwCount);
				RegCloseKey(hKey);
				if( rc != ERROR_SUCCESS )
					hr = HRESULT_FROM_WIN32(rc);
			}
		}
  }
  catch( HRESULT hr )
  {
		regKey.Close();
		return hr;
  }
	regKey.Close();
	return S_OK;
}

ISAPrfcContextSource * CRfcResourceDispenser::m_pISAPrfcContextSource;
CComAutoCriticalSection CRfcResourceDispenser::m_cs;
_TCHAR g_szSAPMTX_H[] = _T("sapmtx.h");
#endif /* SAPMTX_GLOBAL */

