

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Jan 16 00:23:20 2012
 */
/* Compiler settings for sapconn.idl:
    Oicf, W1, Zp8, env=Win64 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __sapconn_h__
#define __sapconn_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISAPConnector_FWD_DEFINED__
#define __ISAPConnector_FWD_DEFINED__
typedef interface ISAPConnector ISAPConnector;
#endif 	/* __ISAPConnector_FWD_DEFINED__ */


#ifndef __ISAPSession_FWD_DEFINED__
#define __ISAPSession_FWD_DEFINED__
typedef interface ISAPSession ISAPSession;
#endif 	/* __ISAPSession_FWD_DEFINED__ */


#ifndef __ISAPCatalog_FWD_DEFINED__
#define __ISAPCatalog_FWD_DEFINED__
typedef interface ISAPCatalog ISAPCatalog;
#endif 	/* __ISAPCatalog_FWD_DEFINED__ */


#ifndef __ISAPCatalog4C_FWD_DEFINED__
#define __ISAPCatalog4C_FWD_DEFINED__
typedef interface ISAPCatalog4C ISAPCatalog4C;
#endif 	/* __ISAPCatalog4C_FWD_DEFINED__ */


#ifndef __ISAPTRfcConnector_FWD_DEFINED__
#define __ISAPTRfcConnector_FWD_DEFINED__
typedef interface ISAPTRfcConnector ISAPTRfcConnector;
#endif 	/* __ISAPTRfcConnector_FWD_DEFINED__ */


#ifndef __ISAPQRfcConnector_FWD_DEFINED__
#define __ISAPQRfcConnector_FWD_DEFINED__
typedef interface ISAPQRfcConnector ISAPQRfcConnector;
#endif 	/* __ISAPQRfcConnector_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ISAPConnector_INTERFACE_DEFINED__
#define __ISAPConnector_INTERFACE_DEFINED__

/* interface ISAPConnector */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISAPConnector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B933F810-DC5C-11d2-B80B-00A0C9308BE6")
    ISAPConnector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Destination( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Language( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Client( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutSessionInfo( 
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AdviseRfcGuiSink( 
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitWork( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectionAttribute( 
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepSAPContext( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_KeepSAPContext( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitWorkAndWait( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RollbackWork( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPConnectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPConnector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPConnector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPConnector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISAPConnector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISAPConnector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISAPConnector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISAPConnector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            ISAPConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            ISAPConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            ISAPConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserID )( 
            ISAPConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            ISAPConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            ISAPConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            ISAPConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            ISAPConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Client )( 
            ISAPConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutSessionInfo )( 
            ISAPConnector * This,
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AdviseRfcGuiSink )( 
            ISAPConnector * This,
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitWork )( 
            ISAPConnector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPConnector * This,
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepSAPContext )( 
            ISAPConnector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepSAPContext )( 
            ISAPConnector * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitWorkAndWait )( 
            ISAPConnector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RollbackWork )( 
            ISAPConnector * This);
        
        END_INTERFACE
    } ISAPConnectorVtbl;

    interface ISAPConnector
    {
        CONST_VTBL struct ISAPConnectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPConnector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPConnector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPConnector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPConnector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAPConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAPConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAPConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAPConnector_get_Destination(This,pVal)	\
    (This)->lpVtbl -> get_Destination(This,pVal)

#define ISAPConnector_put_Destination(This,newVal)	\
    (This)->lpVtbl -> put_Destination(This,newVal)

#define ISAPConnector_get_UserID(This,pVal)	\
    (This)->lpVtbl -> get_UserID(This,pVal)

#define ISAPConnector_put_UserID(This,newVal)	\
    (This)->lpVtbl -> put_UserID(This,newVal)

#define ISAPConnector_put_Password(This,newVal)	\
    (This)->lpVtbl -> put_Password(This,newVal)

#define ISAPConnector_get_Language(This,pVal)	\
    (This)->lpVtbl -> get_Language(This,pVal)

#define ISAPConnector_put_Language(This,newVal)	\
    (This)->lpVtbl -> put_Language(This,newVal)

#define ISAPConnector_get_Client(This,pVal)	\
    (This)->lpVtbl -> get_Client(This,pVal)

#define ISAPConnector_put_Client(This,newVal)	\
    (This)->lpVtbl -> put_Client(This,newVal)

#define ISAPConnector_PutSessionInfo(This,Destination,UserID,Password,Language,Client)	\
    (This)->lpVtbl -> PutSessionInfo(This,Destination,UserID,Password,Language,Client)

#define ISAPConnector_AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)	\
    (This)->lpVtbl -> AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)

#define ISAPConnector_CommitWork(This)	\
    (This)->lpVtbl -> CommitWork(This)

#define ISAPConnector_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#define ISAPConnector_get_KeepSAPContext(This,pVal)	\
    (This)->lpVtbl -> get_KeepSAPContext(This,pVal)

#define ISAPConnector_put_KeepSAPContext(This,newVal)	\
    (This)->lpVtbl -> put_KeepSAPContext(This,newVal)

#define ISAPConnector_CommitWorkAndWait(This)	\
    (This)->lpVtbl -> CommitWorkAndWait(This)

#define ISAPConnector_RollbackWork(This)	\
    (This)->lpVtbl -> RollbackWork(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPConnector_get_Destination_Proxy( 
    ISAPConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPConnector_get_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_Destination_Proxy( 
    ISAPConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPConnector_put_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPConnector_get_UserID_Proxy( 
    ISAPConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPConnector_get_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_UserID_Proxy( 
    ISAPConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPConnector_put_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_Password_Proxy( 
    ISAPConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPConnector_put_Password_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPConnector_get_Language_Proxy( 
    ISAPConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPConnector_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_Language_Proxy( 
    ISAPConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPConnector_put_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPConnector_get_Client_Proxy( 
    ISAPConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPConnector_get_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_Client_Proxy( 
    ISAPConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPConnector_put_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_PutSessionInfo_Proxy( 
    ISAPConnector * This,
    /* [optional][in] */ BSTR Destination,
    /* [optional][in] */ BSTR UserID,
    /* [optional][in] */ BSTR Password,
    /* [optional][in] */ BSTR Language,
    /* [optional][in] */ BSTR Client);


void __RPC_STUB ISAPConnector_PutSessionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_AdviseRfcGuiSink_Proxy( 
    ISAPConnector * This,
    /* [in] */ IDispatch *pIRfcGuiSink,
    /* [in] */ short AbapDebug,
    /* [in] */ short UseSapGui);


void __RPC_STUB ISAPConnector_AdviseRfcGuiSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_CommitWork_Proxy( 
    ISAPConnector * This);


void __RPC_STUB ISAPConnector_CommitWork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_GetConnectionAttribute_Proxy( 
    ISAPConnector * This,
    /* [optional][in] */ BSTR AttrName,
    /* [retval][out] */ VARIANT *pAttrValue);


void __RPC_STUB ISAPConnector_GetConnectionAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPConnector_get_KeepSAPContext_Proxy( 
    ISAPConnector * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISAPConnector_get_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPConnector_put_KeepSAPContext_Proxy( 
    ISAPConnector * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISAPConnector_put_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_CommitWorkAndWait_Proxy( 
    ISAPConnector * This);


void __RPC_STUB ISAPConnector_CommitWorkAndWait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPConnector_RollbackWork_Proxy( 
    ISAPConnector * This);


void __RPC_STUB ISAPConnector_RollbackWork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPConnector_INTERFACE_DEFINED__ */


#ifndef __ISAPSession_INTERFACE_DEFINED__
#define __ISAPSession_INTERFACE_DEFINED__

/* interface ISAPSession */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISAPSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B933F811-DC5C-11d2-B80B-00A0C9308BE6")
    ISAPSession : public ISAPConnector
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logon( 
            /* [optional][out] */ BSTR *pErrInfo,
            /* [retval][out] */ VARIANT_BOOL *pSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [in] */ BSTR ProgID,
            /* [optional][in] */ BSTR InterfID,
            /* [retval][out] */ IDispatch **pObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPSession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISAPSession * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISAPSession * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISAPSession * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISAPSession * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            ISAPSession * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            ISAPSession * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            ISAPSession * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserID )( 
            ISAPSession * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            ISAPSession * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            ISAPSession * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            ISAPSession * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            ISAPSession * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Client )( 
            ISAPSession * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutSessionInfo )( 
            ISAPSession * This,
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AdviseRfcGuiSink )( 
            ISAPSession * This,
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitWork )( 
            ISAPSession * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPSession * This,
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepSAPContext )( 
            ISAPSession * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepSAPContext )( 
            ISAPSession * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitWorkAndWait )( 
            ISAPSession * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RollbackWork )( 
            ISAPSession * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Logon )( 
            ISAPSession * This,
            /* [optional][out] */ BSTR *pErrInfo,
            /* [retval][out] */ VARIANT_BOOL *pSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            ISAPSession * This,
            /* [in] */ BSTR ProgID,
            /* [optional][in] */ BSTR InterfID,
            /* [retval][out] */ IDispatch **pObject);
        
        END_INTERFACE
    } ISAPSessionVtbl;

    interface ISAPSession
    {
        CONST_VTBL struct ISAPSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAPSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAPSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAPSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAPSession_get_Destination(This,pVal)	\
    (This)->lpVtbl -> get_Destination(This,pVal)

#define ISAPSession_put_Destination(This,newVal)	\
    (This)->lpVtbl -> put_Destination(This,newVal)

#define ISAPSession_get_UserID(This,pVal)	\
    (This)->lpVtbl -> get_UserID(This,pVal)

#define ISAPSession_put_UserID(This,newVal)	\
    (This)->lpVtbl -> put_UserID(This,newVal)

#define ISAPSession_put_Password(This,newVal)	\
    (This)->lpVtbl -> put_Password(This,newVal)

#define ISAPSession_get_Language(This,pVal)	\
    (This)->lpVtbl -> get_Language(This,pVal)

#define ISAPSession_put_Language(This,newVal)	\
    (This)->lpVtbl -> put_Language(This,newVal)

#define ISAPSession_get_Client(This,pVal)	\
    (This)->lpVtbl -> get_Client(This,pVal)

#define ISAPSession_put_Client(This,newVal)	\
    (This)->lpVtbl -> put_Client(This,newVal)

#define ISAPSession_PutSessionInfo(This,Destination,UserID,Password,Language,Client)	\
    (This)->lpVtbl -> PutSessionInfo(This,Destination,UserID,Password,Language,Client)

#define ISAPSession_AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)	\
    (This)->lpVtbl -> AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)

#define ISAPSession_CommitWork(This)	\
    (This)->lpVtbl -> CommitWork(This)

#define ISAPSession_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#define ISAPSession_get_KeepSAPContext(This,pVal)	\
    (This)->lpVtbl -> get_KeepSAPContext(This,pVal)

#define ISAPSession_put_KeepSAPContext(This,newVal)	\
    (This)->lpVtbl -> put_KeepSAPContext(This,newVal)

#define ISAPSession_CommitWorkAndWait(This)	\
    (This)->lpVtbl -> CommitWorkAndWait(This)

#define ISAPSession_RollbackWork(This)	\
    (This)->lpVtbl -> RollbackWork(This)


#define ISAPSession_Logon(This,pErrInfo,pSuccess)	\
    (This)->lpVtbl -> Logon(This,pErrInfo,pSuccess)

#define ISAPSession_CreateInstance(This,ProgID,InterfID,pObject)	\
    (This)->lpVtbl -> CreateInstance(This,ProgID,InterfID,pObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPSession_Logon_Proxy( 
    ISAPSession * This,
    /* [optional][out] */ BSTR *pErrInfo,
    /* [retval][out] */ VARIANT_BOOL *pSuccess);


void __RPC_STUB ISAPSession_Logon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPSession_CreateInstance_Proxy( 
    ISAPSession * This,
    /* [in] */ BSTR ProgID,
    /* [optional][in] */ BSTR InterfID,
    /* [retval][out] */ IDispatch **pObject);


void __RPC_STUB ISAPSession_CreateInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPSession_INTERFACE_DEFINED__ */


#ifndef __ISAPCatalog_INTERFACE_DEFINED__
#define __ISAPCatalog_INTERFACE_DEFINED__

/* interface ISAPCatalog */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISAPCatalog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7be0d2e2-e620-11d1-889f-080009e82b31")
    ISAPCatalog : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSchemata( 
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClasses( 
            /* [optional][in] */ BSTR schemaName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMethods( 
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTypes( 
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMethodParameters( 
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [optional][in] */ BSTR methodName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTypeColumns( 
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [optional][in] */ BSTR typeName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPCatalogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPCatalog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPCatalog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPCatalog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISAPCatalog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISAPCatalog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISAPCatalog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISAPCatalog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSchemata )( 
            ISAPCatalog * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClasses )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMethods )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTypes )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMethodParameters )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [optional][in] */ BSTR methodName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTypeColumns )( 
            ISAPCatalog * This,
            /* [optional][in] */ BSTR schemaName,
            /* [optional][in] */ BSTR className,
            /* [optional][in] */ BSTR typeName,
            /* [retval][out] */ IDispatch **ppTab);
        
        END_INTERFACE
    } ISAPCatalogVtbl;

    interface ISAPCatalog
    {
        CONST_VTBL struct ISAPCatalogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPCatalog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPCatalog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPCatalog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPCatalog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAPCatalog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAPCatalog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAPCatalog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAPCatalog_GetSchemata(This,ppTab)	\
    (This)->lpVtbl -> GetSchemata(This,ppTab)

#define ISAPCatalog_GetClasses(This,schemaName,ppTab)	\
    (This)->lpVtbl -> GetClasses(This,schemaName,ppTab)

#define ISAPCatalog_GetMethods(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetMethods(This,schemaName,className,ppTab)

#define ISAPCatalog_GetProperties(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetProperties(This,schemaName,className,ppTab)

#define ISAPCatalog_GetTypes(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetTypes(This,schemaName,className,ppTab)

#define ISAPCatalog_GetMethodParameters(This,schemaName,className,methodName,ppTab)	\
    (This)->lpVtbl -> GetMethodParameters(This,schemaName,className,methodName,ppTab)

#define ISAPCatalog_GetTypeColumns(This,schemaName,className,typeName,ppTab)	\
    (This)->lpVtbl -> GetTypeColumns(This,schemaName,className,typeName,ppTab)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetSchemata_Proxy( 
    ISAPCatalog * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetSchemata_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetClasses_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetClasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetMethods_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [optional][in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetProperties_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [optional][in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetTypes_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [optional][in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetMethodParameters_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [optional][in] */ BSTR className,
    /* [optional][in] */ BSTR methodName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetMethodParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPCatalog_GetTypeColumns_Proxy( 
    ISAPCatalog * This,
    /* [optional][in] */ BSTR schemaName,
    /* [optional][in] */ BSTR className,
    /* [optional][in] */ BSTR typeName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog_GetTypeColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPCatalog_INTERFACE_DEFINED__ */


#ifndef __ISAPCatalog4C_INTERFACE_DEFINED__
#define __ISAPCatalog4C_INTERFACE_DEFINED__

/* interface ISAPCatalog4C */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPCatalog4C;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB62A080-3FE8-11d1-ADC1-080009D213D2")
    ISAPCatalog4C : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateFromData( 
            /* [string][in] */ const OLECHAR *wcsSchemaName,
            /* [in] */ unsigned long lObjLen,
            /* [size_is][in] */ byte *pScObj,
            /* [in] */ unsigned long lVerbLen,
            /* [size_is][in] */ byte *pScVerb) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeType( 
            /* [string][in] */ const unsigned char *typeName,
            /* [string][in] */ const unsigned char *typeAbapName,
            /* [string][in] */ const unsigned char *typeDescription,
            /* [in] */ unsigned long lTypeEntryLen,
            /* [in] */ byte *pTypeEntries,
            /* [in] */ unsigned long lEntries) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSchemata( 
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetClasses( 
            /* [in] */ BSTR schemaName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMethods( 
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTypes( 
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMethodParameters( 
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR methodName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTypeColumns( 
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR typeName,
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPCatalog4CVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPCatalog4C * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPCatalog4C * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPCatalog4C * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateFromData )( 
            ISAPCatalog4C * This,
            /* [string][in] */ const OLECHAR *wcsSchemaName,
            /* [in] */ unsigned long lObjLen,
            /* [size_is][in] */ byte *pScObj,
            /* [in] */ unsigned long lVerbLen,
            /* [size_is][in] */ byte *pScVerb);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeType )( 
            ISAPCatalog4C * This,
            /* [string][in] */ const unsigned char *typeName,
            /* [string][in] */ const unsigned char *typeAbapName,
            /* [string][in] */ const unsigned char *typeDescription,
            /* [in] */ unsigned long lTypeEntryLen,
            /* [in] */ byte *pTypeEntries,
            /* [in] */ unsigned long lEntries);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSchemata )( 
            ISAPCatalog4C * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetClasses )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethods )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTypes )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethodParameters )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR methodName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTypeColumns )( 
            ISAPCatalog4C * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR typeName,
            /* [retval][out] */ IDispatch **ppTab);
        
        END_INTERFACE
    } ISAPCatalog4CVtbl;

    interface ISAPCatalog4C
    {
        CONST_VTBL struct ISAPCatalog4CVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPCatalog4C_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPCatalog4C_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPCatalog4C_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPCatalog4C_CreateFromData(This,wcsSchemaName,lObjLen,pScObj,lVerbLen,pScVerb)	\
    (This)->lpVtbl -> CreateFromData(This,wcsSchemaName,lObjLen,pScObj,lVerbLen,pScVerb)

#define ISAPCatalog4C_InitializeType(This,typeName,typeAbapName,typeDescription,lTypeEntryLen,pTypeEntries,lEntries)	\
    (This)->lpVtbl -> InitializeType(This,typeName,typeAbapName,typeDescription,lTypeEntryLen,pTypeEntries,lEntries)

#define ISAPCatalog4C_GetSchemata(This,ppTab)	\
    (This)->lpVtbl -> GetSchemata(This,ppTab)

#define ISAPCatalog4C_GetClasses(This,schemaName,ppTab)	\
    (This)->lpVtbl -> GetClasses(This,schemaName,ppTab)

#define ISAPCatalog4C_GetMethods(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetMethods(This,schemaName,className,ppTab)

#define ISAPCatalog4C_GetProperties(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetProperties(This,schemaName,className,ppTab)

#define ISAPCatalog4C_GetTypes(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetTypes(This,schemaName,className,ppTab)

#define ISAPCatalog4C_GetMethodParameters(This,schemaName,className,methodName,ppTab)	\
    (This)->lpVtbl -> GetMethodParameters(This,schemaName,className,methodName,ppTab)

#define ISAPCatalog4C_GetTypeColumns(This,schemaName,className,typeName,ppTab)	\
    (This)->lpVtbl -> GetTypeColumns(This,schemaName,className,typeName,ppTab)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_CreateFromData_Proxy( 
    ISAPCatalog4C * This,
    /* [string][in] */ const OLECHAR *wcsSchemaName,
    /* [in] */ unsigned long lObjLen,
    /* [size_is][in] */ byte *pScObj,
    /* [in] */ unsigned long lVerbLen,
    /* [size_is][in] */ byte *pScVerb);


void __RPC_STUB ISAPCatalog4C_CreateFromData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_InitializeType_Proxy( 
    ISAPCatalog4C * This,
    /* [string][in] */ const unsigned char *typeName,
    /* [string][in] */ const unsigned char *typeAbapName,
    /* [string][in] */ const unsigned char *typeDescription,
    /* [in] */ unsigned long lTypeEntryLen,
    /* [in] */ byte *pTypeEntries,
    /* [in] */ unsigned long lEntries);


void __RPC_STUB ISAPCatalog4C_InitializeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetSchemata_Proxy( 
    ISAPCatalog4C * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetSchemata_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetClasses_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetClasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetMethods_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetProperties_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetTypes_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetMethodParameters_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [in] */ BSTR methodName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetMethodParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4C_GetTypeColumns_Proxy( 
    ISAPCatalog4C * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [in] */ BSTR typeName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4C_GetTypeColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPCatalog4C_INTERFACE_DEFINED__ */


#ifndef __ISAPTRfcConnector_INTERFACE_DEFINED__
#define __ISAPTRfcConnector_INTERFACE_DEFINED__

/* interface ISAPTRfcConnector */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISAPTRfcConnector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B0B9E2C0-7A83-4c2a-9075-A9BEC92D897B")
    ISAPTRfcConnector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Destination( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Language( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Client( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutSessionInfo( 
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AdviseRfcGuiSink( 
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectionAttribute( 
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepSAPContext( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_KeepSAPContext( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNewTID( 
            /* [retval][out] */ BSTR *TID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Confirm( 
            /* [optional][in] */ BSTR TID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPTRfcConnectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPTRfcConnector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPTRfcConnector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPTRfcConnector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISAPTRfcConnector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISAPTRfcConnector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISAPTRfcConnector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISAPTRfcConnector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserID )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Client )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutSessionInfo )( 
            ISAPTRfcConnector * This,
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AdviseRfcGuiSink )( 
            ISAPTRfcConnector * This,
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPTRfcConnector * This,
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepSAPContext )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepSAPContext )( 
            ISAPTRfcConnector * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNewTID )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *TID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TID )( 
            ISAPTRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TID )( 
            ISAPTRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Confirm )( 
            ISAPTRfcConnector * This,
            /* [optional][in] */ BSTR TID);
        
        END_INTERFACE
    } ISAPTRfcConnectorVtbl;

    interface ISAPTRfcConnector
    {
        CONST_VTBL struct ISAPTRfcConnectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPTRfcConnector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPTRfcConnector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPTRfcConnector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPTRfcConnector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAPTRfcConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAPTRfcConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAPTRfcConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAPTRfcConnector_get_Destination(This,pVal)	\
    (This)->lpVtbl -> get_Destination(This,pVal)

#define ISAPTRfcConnector_put_Destination(This,newVal)	\
    (This)->lpVtbl -> put_Destination(This,newVal)

#define ISAPTRfcConnector_get_UserID(This,pVal)	\
    (This)->lpVtbl -> get_UserID(This,pVal)

#define ISAPTRfcConnector_put_UserID(This,newVal)	\
    (This)->lpVtbl -> put_UserID(This,newVal)

#define ISAPTRfcConnector_put_Password(This,newVal)	\
    (This)->lpVtbl -> put_Password(This,newVal)

#define ISAPTRfcConnector_get_Language(This,pVal)	\
    (This)->lpVtbl -> get_Language(This,pVal)

#define ISAPTRfcConnector_put_Language(This,newVal)	\
    (This)->lpVtbl -> put_Language(This,newVal)

#define ISAPTRfcConnector_get_Client(This,pVal)	\
    (This)->lpVtbl -> get_Client(This,pVal)

#define ISAPTRfcConnector_put_Client(This,newVal)	\
    (This)->lpVtbl -> put_Client(This,newVal)

#define ISAPTRfcConnector_PutSessionInfo(This,Destination,UserID,Password,Language,Client)	\
    (This)->lpVtbl -> PutSessionInfo(This,Destination,UserID,Password,Language,Client)

#define ISAPTRfcConnector_AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)	\
    (This)->lpVtbl -> AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)

#define ISAPTRfcConnector_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#define ISAPTRfcConnector_get_KeepSAPContext(This,pVal)	\
    (This)->lpVtbl -> get_KeepSAPContext(This,pVal)

#define ISAPTRfcConnector_put_KeepSAPContext(This,newVal)	\
    (This)->lpVtbl -> put_KeepSAPContext(This,newVal)

#define ISAPTRfcConnector_GetNewTID(This,TID)	\
    (This)->lpVtbl -> GetNewTID(This,TID)

#define ISAPTRfcConnector_get_TID(This,pVal)	\
    (This)->lpVtbl -> get_TID(This,pVal)

#define ISAPTRfcConnector_put_TID(This,newVal)	\
    (This)->lpVtbl -> put_TID(This,newVal)

#define ISAPTRfcConnector_Confirm(This,TID)	\
    (This)->lpVtbl -> Confirm(This,TID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_Destination_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPTRfcConnector_get_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_Destination_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_UserID_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPTRfcConnector_get_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_UserID_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_Password_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_Password_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_Language_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPTRfcConnector_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_Language_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_Client_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPTRfcConnector_get_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_Client_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_PutSessionInfo_Proxy( 
    ISAPTRfcConnector * This,
    /* [optional][in] */ BSTR Destination,
    /* [optional][in] */ BSTR UserID,
    /* [optional][in] */ BSTR Password,
    /* [optional][in] */ BSTR Language,
    /* [optional][in] */ BSTR Client);


void __RPC_STUB ISAPTRfcConnector_PutSessionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_AdviseRfcGuiSink_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ IDispatch *pIRfcGuiSink,
    /* [in] */ short AbapDebug,
    /* [in] */ short UseSapGui);


void __RPC_STUB ISAPTRfcConnector_AdviseRfcGuiSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_GetConnectionAttribute_Proxy( 
    ISAPTRfcConnector * This,
    /* [optional][in] */ BSTR AttrName,
    /* [retval][out] */ VARIANT *pAttrValue);


void __RPC_STUB ISAPTRfcConnector_GetConnectionAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_KeepSAPContext_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISAPTRfcConnector_get_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_KeepSAPContext_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISAPTRfcConnector_put_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_GetNewTID_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *TID);


void __RPC_STUB ISAPTRfcConnector_GetNewTID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_get_TID_Proxy( 
    ISAPTRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPTRfcConnector_get_TID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_put_TID_Proxy( 
    ISAPTRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPTRfcConnector_put_TID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPTRfcConnector_Confirm_Proxy( 
    ISAPTRfcConnector * This,
    /* [optional][in] */ BSTR TID);


void __RPC_STUB ISAPTRfcConnector_Confirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPTRfcConnector_INTERFACE_DEFINED__ */


#ifndef __ISAPQRfcConnector_INTERFACE_DEFINED__
#define __ISAPQRfcConnector_INTERFACE_DEFINED__

/* interface ISAPQRfcConnector */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISAPQRfcConnector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F66023A4-EB0D-45ce-A047-9A82F7BA322C")
    ISAPQRfcConnector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Destination( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Language( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Client( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutSessionInfo( 
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectionAttribute( 
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepSAPContext( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_KeepSAPContext( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNewTID( 
            /* [retval][out] */ BSTR *TID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QueueName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QueueName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QueueItemIndex( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QueueItemIndex( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Confirm( 
            /* [optional][in] */ BSTR TID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ActivateQueue( 
            /* [in] */ BSTR QueueName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeactivateQueue( 
            /* [in] */ BSTR QueueName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPQRfcConnectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPQRfcConnector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPQRfcConnector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPQRfcConnector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISAPQRfcConnector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISAPQRfcConnector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISAPQRfcConnector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISAPQRfcConnector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserID )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Client )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutSessionInfo )( 
            ISAPQRfcConnector * This,
            /* [optional][in] */ BSTR Destination,
            /* [optional][in] */ BSTR UserID,
            /* [optional][in] */ BSTR Password,
            /* [optional][in] */ BSTR Language,
            /* [optional][in] */ BSTR Client);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPQRfcConnector * This,
            /* [optional][in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepSAPContext )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepSAPContext )( 
            ISAPQRfcConnector * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNewTID )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *TID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TID )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TID )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueueName )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueueName )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueueItemIndex )( 
            ISAPQRfcConnector * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueueItemIndex )( 
            ISAPQRfcConnector * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Confirm )( 
            ISAPQRfcConnector * This,
            /* [optional][in] */ BSTR TID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ActivateQueue )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR QueueName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeactivateQueue )( 
            ISAPQRfcConnector * This,
            /* [in] */ BSTR QueueName);
        
        END_INTERFACE
    } ISAPQRfcConnectorVtbl;

    interface ISAPQRfcConnector
    {
        CONST_VTBL struct ISAPQRfcConnectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPQRfcConnector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPQRfcConnector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPQRfcConnector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPQRfcConnector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISAPQRfcConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISAPQRfcConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISAPQRfcConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISAPQRfcConnector_get_Destination(This,pVal)	\
    (This)->lpVtbl -> get_Destination(This,pVal)

#define ISAPQRfcConnector_put_Destination(This,newVal)	\
    (This)->lpVtbl -> put_Destination(This,newVal)

#define ISAPQRfcConnector_get_UserID(This,pVal)	\
    (This)->lpVtbl -> get_UserID(This,pVal)

#define ISAPQRfcConnector_put_UserID(This,newVal)	\
    (This)->lpVtbl -> put_UserID(This,newVal)

#define ISAPQRfcConnector_put_Password(This,newVal)	\
    (This)->lpVtbl -> put_Password(This,newVal)

#define ISAPQRfcConnector_get_Language(This,pVal)	\
    (This)->lpVtbl -> get_Language(This,pVal)

#define ISAPQRfcConnector_put_Language(This,newVal)	\
    (This)->lpVtbl -> put_Language(This,newVal)

#define ISAPQRfcConnector_get_Client(This,pVal)	\
    (This)->lpVtbl -> get_Client(This,pVal)

#define ISAPQRfcConnector_put_Client(This,newVal)	\
    (This)->lpVtbl -> put_Client(This,newVal)

#define ISAPQRfcConnector_PutSessionInfo(This,Destination,UserID,Password,Language,Client)	\
    (This)->lpVtbl -> PutSessionInfo(This,Destination,UserID,Password,Language,Client)

#define ISAPQRfcConnector_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#define ISAPQRfcConnector_get_KeepSAPContext(This,pVal)	\
    (This)->lpVtbl -> get_KeepSAPContext(This,pVal)

#define ISAPQRfcConnector_put_KeepSAPContext(This,newVal)	\
    (This)->lpVtbl -> put_KeepSAPContext(This,newVal)

#define ISAPQRfcConnector_GetNewTID(This,TID)	\
    (This)->lpVtbl -> GetNewTID(This,TID)

#define ISAPQRfcConnector_get_TID(This,pVal)	\
    (This)->lpVtbl -> get_TID(This,pVal)

#define ISAPQRfcConnector_put_TID(This,newVal)	\
    (This)->lpVtbl -> put_TID(This,newVal)

#define ISAPQRfcConnector_get_QueueName(This,pVal)	\
    (This)->lpVtbl -> get_QueueName(This,pVal)

#define ISAPQRfcConnector_put_QueueName(This,newVal)	\
    (This)->lpVtbl -> put_QueueName(This,newVal)

#define ISAPQRfcConnector_get_QueueItemIndex(This,pVal)	\
    (This)->lpVtbl -> get_QueueItemIndex(This,pVal)

#define ISAPQRfcConnector_put_QueueItemIndex(This,newVal)	\
    (This)->lpVtbl -> put_QueueItemIndex(This,newVal)

#define ISAPQRfcConnector_Confirm(This,TID)	\
    (This)->lpVtbl -> Confirm(This,TID)

#define ISAPQRfcConnector_ActivateQueue(This,QueueName)	\
    (This)->lpVtbl -> ActivateQueue(This,QueueName)

#define ISAPQRfcConnector_DeactivateQueue(This,QueueName)	\
    (This)->lpVtbl -> DeactivateQueue(This,QueueName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_Destination_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_Destination_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_UserID_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_UserID_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_UserID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_Password_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_Password_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_Language_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_Language_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_Client_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_Client_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_PutSessionInfo_Proxy( 
    ISAPQRfcConnector * This,
    /* [optional][in] */ BSTR Destination,
    /* [optional][in] */ BSTR UserID,
    /* [optional][in] */ BSTR Password,
    /* [optional][in] */ BSTR Language,
    /* [optional][in] */ BSTR Client);


void __RPC_STUB ISAPQRfcConnector_PutSessionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_GetConnectionAttribute_Proxy( 
    ISAPQRfcConnector * This,
    /* [optional][in] */ BSTR AttrName,
    /* [retval][out] */ VARIANT *pAttrValue);


void __RPC_STUB ISAPQRfcConnector_GetConnectionAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_KeepSAPContext_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISAPQRfcConnector_get_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_KeepSAPContext_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISAPQRfcConnector_put_KeepSAPContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_GetNewTID_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *TID);


void __RPC_STUB ISAPQRfcConnector_GetNewTID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_TID_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_TID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_TID_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_TID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_QueueName_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISAPQRfcConnector_get_QueueName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_QueueName_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISAPQRfcConnector_put_QueueName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_get_QueueItemIndex_Proxy( 
    ISAPQRfcConnector * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISAPQRfcConnector_get_QueueItemIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_put_QueueItemIndex_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ long newVal);


void __RPC_STUB ISAPQRfcConnector_put_QueueItemIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_Confirm_Proxy( 
    ISAPQRfcConnector * This,
    /* [optional][in] */ BSTR TID);


void __RPC_STUB ISAPQRfcConnector_Confirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_ActivateQueue_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR QueueName);


void __RPC_STUB ISAPQRfcConnector_ActivateQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISAPQRfcConnector_DeactivateQueue_Proxy( 
    ISAPQRfcConnector * This,
    /* [in] */ BSTR QueueName);


void __RPC_STUB ISAPQRfcConnector_DeactivateQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPQRfcConnector_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


