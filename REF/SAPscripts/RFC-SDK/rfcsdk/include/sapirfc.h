

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sun Jan 15 20:28:11 2012
 */
/* Compiler settings for sapirfc.idl:
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

#ifndef __sapirfc_h__
#define __sapirfc_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISAPrfcITab_FWD_DEFINED__
#define __ISAPrfcITab_FWD_DEFINED__
typedef interface ISAPrfcITab ISAPrfcITab;
#endif 	/* __ISAPrfcITab_FWD_DEFINED__ */


#ifndef __ISAPrfcLocalITab_FWD_DEFINED__
#define __ISAPrfcLocalITab_FWD_DEFINED__
typedef interface ISAPrfcLocalITab ISAPrfcLocalITab;
#endif 	/* __ISAPrfcLocalITab_FWD_DEFINED__ */


#ifndef __ISAPrfcITabHandleAccess_FWD_DEFINED__
#define __ISAPrfcITabHandleAccess_FWD_DEFINED__
typedef interface ISAPrfcITabHandleAccess ISAPrfcITabHandleAccess;
#endif 	/* __ISAPrfcITabHandleAccess_FWD_DEFINED__ */


#ifndef __ISAPrfcStructDesc_FWD_DEFINED__
#define __ISAPrfcStructDesc_FWD_DEFINED__
typedef interface ISAPrfcStructDesc ISAPrfcStructDesc;
#endif 	/* __ISAPrfcStructDesc_FWD_DEFINED__ */


#ifndef __ISAPrfcStructHandleAccess_FWD_DEFINED__
#define __ISAPrfcStructHandleAccess_FWD_DEFINED__
typedef interface ISAPrfcStructHandleAccess ISAPrfcStructHandleAccess;
#endif 	/* __ISAPrfcStructHandleAccess_FWD_DEFINED__ */


#ifndef __ISAPrfcStructView_FWD_DEFINED__
#define __ISAPrfcStructView_FWD_DEFINED__
typedef interface ISAPrfcStructView ISAPrfcStructView;
#endif 	/* __ISAPrfcStructView_FWD_DEFINED__ */


#ifndef __ISAPrfcDataConvert_FWD_DEFINED__
#define __ISAPrfcDataConvert_FWD_DEFINED__
typedef interface ISAPrfcDataConvert ISAPrfcDataConvert;
#endif 	/* __ISAPrfcDataConvert_FWD_DEFINED__ */


#ifndef __ISAPrfcITab2Recordset_FWD_DEFINED__
#define __ISAPrfcITab2Recordset_FWD_DEFINED__
typedef interface ISAPrfcITab2Recordset ISAPrfcITab2Recordset;
#endif 	/* __ISAPrfcITab2Recordset_FWD_DEFINED__ */


#ifndef __ISAPrfcStruct2OLEDB_FWD_DEFINED__
#define __ISAPrfcStruct2OLEDB_FWD_DEFINED__
typedef interface ISAPrfcStruct2OLEDB ISAPrfcStruct2OLEDB;
#endif 	/* __ISAPrfcStruct2OLEDB_FWD_DEFINED__ */


#ifndef __ISAPrfcStruct2OLEDBHinted_FWD_DEFINED__
#define __ISAPrfcStruct2OLEDBHinted_FWD_DEFINED__
typedef interface ISAPrfcStruct2OLEDBHinted ISAPrfcStruct2OLEDBHinted;
#endif 	/* __ISAPrfcStruct2OLEDBHinted_FWD_DEFINED__ */


#ifndef __ISAPrfcBind_FWD_DEFINED__
#define __ISAPrfcBind_FWD_DEFINED__
typedef interface ISAPrfcBind ISAPrfcBind;
#endif 	/* __ISAPrfcBind_FWD_DEFINED__ */


#ifndef __IRfcProxy_FWD_DEFINED__
#define __IRfcProxy_FWD_DEFINED__
typedef interface IRfcProxy IRfcProxy;
#endif 	/* __IRfcProxy_FWD_DEFINED__ */


#ifndef __IRfcAccessStub_FWD_DEFINED__
#define __IRfcAccessStub_FWD_DEFINED__
typedef interface IRfcAccessStub IRfcAccessStub;
#endif 	/* __IRfcAccessStub_FWD_DEFINED__ */


#ifndef __ICCMonitor_FWD_DEFINED__
#define __ICCMonitor_FWD_DEFINED__
typedef interface ICCMonitor ICCMonitor;
#endif 	/* __ICCMonitor_FWD_DEFINED__ */


#ifndef __IRfcHelper1_FWD_DEFINED__
#define __IRfcHelper1_FWD_DEFINED__
typedef interface IRfcHelper1 IRfcHelper1;
#endif 	/* __IRfcHelper1_FWD_DEFINED__ */


#ifndef __ISAPrfcContextRD_FWD_DEFINED__
#define __ISAPrfcContextRD_FWD_DEFINED__
typedef interface ISAPrfcContextRD ISAPrfcContextRD;
#endif 	/* __ISAPrfcContextRD_FWD_DEFINED__ */


#ifndef __ISAPrfcContext_FWD_DEFINED__
#define __ISAPrfcContext_FWD_DEFINED__
typedef interface ISAPrfcContext ISAPrfcContext;
#endif 	/* __ISAPrfcContext_FWD_DEFINED__ */


#ifndef __ISAPrfcContext2_FWD_DEFINED__
#define __ISAPrfcContext2_FWD_DEFINED__
typedef interface ISAPrfcContext2 ISAPrfcContext2;
#endif 	/* __ISAPrfcContext2_FWD_DEFINED__ */


#ifndef __ISAPrfcContextSource_FWD_DEFINED__
#define __ISAPrfcContextSource_FWD_DEFINED__
typedef interface ISAPrfcContextSource ISAPrfcContextSource;
#endif 	/* __ISAPrfcContextSource_FWD_DEFINED__ */


#ifndef __ISAPrfcContextSource2_FWD_DEFINED__
#define __ISAPrfcContextSource2_FWD_DEFINED__
typedef interface ISAPrfcContextSource2 ISAPrfcContextSource2;
#endif 	/* __ISAPrfcContextSource2_FWD_DEFINED__ */


#ifndef __ISAPTxStart_FWD_DEFINED__
#define __ISAPTxStart_FWD_DEFINED__
typedef interface ISAPTxStart ISAPTxStart;
#endif 	/* __ISAPTxStart_FWD_DEFINED__ */


#ifndef __ISAPrfcTraceU_FWD_DEFINED__
#define __ISAPrfcTraceU_FWD_DEFINED__
typedef interface ISAPrfcTraceU ISAPrfcTraceU;
#endif 	/* __ISAPrfcTraceU_FWD_DEFINED__ */


#ifndef __IRfcGuiSink_FWD_DEFINED__
#define __IRfcGuiSink_FWD_DEFINED__
typedef interface IRfcGuiSink IRfcGuiSink;
#endif 	/* __IRfcGuiSink_FWD_DEFINED__ */


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


#ifndef __ISAPCatalog4CU_FWD_DEFINED__
#define __ISAPCatalog4CU_FWD_DEFINED__
typedef interface ISAPCatalog4CU ISAPCatalog4CU;
#endif 	/* __ISAPCatalog4CU_FWD_DEFINED__ */


#ifndef __ISAPTRfcConnector_FWD_DEFINED__
#define __ISAPTRfcConnector_FWD_DEFINED__
typedef interface ISAPTRfcConnector ISAPTRfcConnector;
#endif 	/* __ISAPTRfcConnector_FWD_DEFINED__ */


#ifndef __ISAPQRfcConnector_FWD_DEFINED__
#define __ISAPQRfcConnector_FWD_DEFINED__
typedef interface ISAPQRfcConnector ISAPQRfcConnector;
#endif 	/* __ISAPQRfcConnector_FWD_DEFINED__ */


#ifndef __CSAPrfcITab_FWD_DEFINED__
#define __CSAPrfcITab_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSAPrfcITab CSAPrfcITab;
#else
typedef struct CSAPrfcITab CSAPrfcITab;
#endif /* __cplusplus */

#endif 	/* __CSAPrfcITab_FWD_DEFINED__ */


#ifndef __CSAPrfcStructDesc_FWD_DEFINED__
#define __CSAPrfcStructDesc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSAPrfcStructDesc CSAPrfcStructDesc;
#else
typedef struct CSAPrfcStructDesc CSAPrfcStructDesc;
#endif /* __cplusplus */

#endif 	/* __CSAPrfcStructDesc_FWD_DEFINED__ */


#ifndef __CSAPrfcStructView_FWD_DEFINED__
#define __CSAPrfcStructView_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSAPrfcStructView CSAPrfcStructView;
#else
typedef struct CSAPrfcStructView CSAPrfcStructView;
#endif /* __cplusplus */

#endif 	/* __CSAPrfcStructView_FWD_DEFINED__ */


#ifndef __CSAPrfcDataConvert_FWD_DEFINED__
#define __CSAPrfcDataConvert_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSAPrfcDataConvert CSAPrfcDataConvert;
#else
typedef struct CSAPrfcDataConvert CSAPrfcDataConvert;
#endif /* __cplusplus */

#endif 	/* __CSAPrfcDataConvert_FWD_DEFINED__ */


#ifndef __RfcProxy_FWD_DEFINED__
#define __RfcProxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcProxy RfcProxy;
#else
typedef struct RfcProxy RfcProxy;
#endif /* __cplusplus */

#endif 	/* __RfcProxy_FWD_DEFINED__ */


#ifndef __RfcContext_FWD_DEFINED__
#define __RfcContext_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcContext RfcContext;
#else
typedef struct RfcContext RfcContext;
#endif /* __cplusplus */

#endif 	/* __RfcContext_FWD_DEFINED__ */


#ifndef __RfcContextSource_FWD_DEFINED__
#define __RfcContextSource_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcContextSource RfcContextSource;
#else
typedef struct RfcContextSource RfcContextSource;
#endif /* __cplusplus */

#endif 	/* __RfcContextSource_FWD_DEFINED__ */


#ifndef __RfcSchemaSource_FWD_DEFINED__
#define __RfcSchemaSource_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcSchemaSource RfcSchemaSource;
#else
typedef struct RfcSchemaSource RfcSchemaSource;
#endif /* __cplusplus */

#endif 	/* __RfcSchemaSource_FWD_DEFINED__ */


#ifndef __SAPTxStart_FWD_DEFINED__
#define __SAPTxStart_FWD_DEFINED__

#ifdef __cplusplus
typedef class SAPTxStart SAPTxStart;
#else
typedef struct SAPTxStart SAPTxStart;
#endif /* __cplusplus */

#endif 	/* __SAPTxStart_FWD_DEFINED__ */


#ifndef __RfcGuiSink_FWD_DEFINED__
#define __RfcGuiSink_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcGuiSink RfcGuiSink;
#else
typedef struct RfcGuiSink RfcGuiSink;
#endif /* __cplusplus */

#endif 	/* __RfcGuiSink_FWD_DEFINED__ */


#ifndef __SapRfcMonitor_FWD_DEFINED__
#define __SapRfcMonitor_FWD_DEFINED__

#ifdef __cplusplus
typedef class SapRfcMonitor SapRfcMonitor;
#else
typedef struct SapRfcMonitor SapRfcMonitor;
#endif /* __cplusplus */

#endif 	/* __SapRfcMonitor_FWD_DEFINED__ */


#ifndef __RfcSession_FWD_DEFINED__
#define __RfcSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class RfcSession RfcSession;
#else
typedef struct RfcSession RfcSession;
#endif /* __cplusplus */

#endif 	/* __RfcSession_FWD_DEFINED__ */


#ifndef __ISAPrfcBind_FWD_DEFINED__
#define __ISAPrfcBind_FWD_DEFINED__
typedef interface ISAPrfcBind ISAPrfcBind;
#endif 	/* __ISAPrfcBind_FWD_DEFINED__ */


#ifndef __ISAPConnector_FWD_DEFINED__
#define __ISAPConnector_FWD_DEFINED__
typedef interface ISAPConnector ISAPConnector;
#endif 	/* __ISAPConnector_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "oaidl.h"
#include "sapobj.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_sapirfc_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  SAP AG
//  Systeme, Anwendungen und Produkte in der Datenverarbeitung
//  (C) Copyright SAP AG 1997 - 1998.
//
//--------------------------------------------------------------------------
//@(#) $Id: //bas/640_REL/src/krn/rfc/sapirfc.idl#1 $ SAP
/*SAPUNICODEOK_FILE*/
//+-------------------------------------------------------------------------
//
//  SAP AG
//  Systeme, Anwendungen und Produkte in der Datenverarbeitung
//  (C) Copyright SAP AG 1997.
//
//--------------------------------------------------------------------------
//@(#) $Id: //bas/640_REL/src/krn/rfc/sapitab.idl#1 $ SAP
#include "saprfc.h"
#include "sapitab.h"
//
#ifndef _RFC_TYPEHANDLE_DEFINED
#define _RFC_TYPEHANDLE_DEFINED
typedef unsigned int RFC_TYPEHANDLE;

#endif






//--------------------------------------------------------------------------
//  CUSTOM error codes:
#define E_SAPRFC_NOT_INITIALIZED	CUSTOM_CTL_SCODE(1000)
#define E_SAPRFC_INVALID_TYPE	CUSTOM_CTL_SCODE(1001)
#define E_SAPRFC_INVALID_LINE	CUSTOM_CTL_SCODE(1002)
#define E_SAPRFC_ALREADY_LOCKED	CUSTOM_CTL_SCODE(1003)
#define E_SAPRFC_NOT_SUPORTED	CUSTOM_CTL_SCODE(1004)
#define E_SAPRFC_BASE_NOT_ALPHA	CUSTOM_CTL_SCODE(1005)
#define E_SAPRFC_BASE_TOO_SHORT	CUSTOM_CTL_SCODE(1006)

#ifndef _RFC_IRFCTYPEKIND
#define _RFC_IRFCTYPEKIND
typedef DWORD IRFCTYPEKIND;


enum IRFCKINDENUM
    {	IRFCTYPE_RFC	= 0,
	IRFCTYPE_OLEDB	= IRFCTYPE_RFC + 1
    } ;
#endif
#ifndef _RFC_IRFCTYPE_CONVERT
#define _RFC_IRFCTYPE_CONVERT
typedef struct tagIRFCTYPE_CONVERT
    {
    IRFCTYPEKIND tKind;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ RFC_TYPEHANDLE rfctype;
        /* [case()] */ WORD dbtype;
        } 	TheType;
    } 	IRFCTYPE_CONVERT;

typedef struct tagIRFCTYPE_CONVERT *PIRFCTYPE_CONVERT;

typedef const IRFCTYPE_CONVERT *PCIRFCTYPE_CONVERT;

#define MKPIRFCTYPE(ps, t)  { ps->tKind = IRFCTYPE_RFC;   ps->TheType.rfctype = t; } 
#define MKPOLEDBTYPE(ps, t) { ps->tKind = IRFCTYPE_OLEDB; ps->TheType.dbtype  = t; } 
#define MKIRFCTYPE(s, t)    { s.tKind   = IRFCTYPE_RFC;   s.TheType.rfctype   = t; } 
#define MKOLEDBTYPE(s, t)   { s.tKind   = IRFCTYPE_OLEDB; s.TheType.dbtype    = t; } 
#endif
#ifndef _RFC_TYPE_ELEMENT_IN_DEFINED
#define _RFC_TYPE_ELEMENT_IN_DEFINED
#define TYPISTRU 33 // for structures
typedef /* [public][public] */ struct __MIDL___MIDL_itf_sapirfc_0000_0002
    {
    /* [string] */ OLECHAR *name;
    RFC_TYPEHANDLE type;
    unsigned long length;
    unsigned long decimals;
    ISAPrfcStructDesc *pStru;
    } 	RFC_TYPE_ELEMENT_IN;

typedef struct __MIDL___MIDL_itf_sapirfc_0000_0002 *PRFC_TYPE_ELEMENT_IN;

#endif
#ifndef _RFC_TYPE_ELEMENT_OUT_DEFINED
#define _RFC_TYPE_ELEMENT_OUT_DEFINED
#define TYPISTRU 33 // for structures
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_sapirfc_0000_0003
    {
    unsigned long offName;
    RFC_TYPEHANDLE type;
    unsigned long length;
    unsigned long decimals;
    ISAPrfcStructDesc *pStru;
    unsigned long offset;
    } 	RFC_TYPE_ELEMENT_OUT;

typedef struct __MIDL___MIDL_itf_sapirfc_0000_0003 *PRFC_TYPE_ELEMENT_OUT;

#endif
#ifndef _RFC_IRFC_TABKIND
#define _RFC_IRFC_TABKIND

enum IRFC_TABKIND
    {	IRFCTK_STANDARD	= 0,
	IRFCTK_SORTED	= IRFCTK_STANDARD + 1,
	IRFCTK_HASHED	= IRFCTK_SORTED + 1
    } ;

enum IRFC_KEYDEF
    {	IRFCKD_LINE	= 0,
	IRFCKD_STANDARD	= IRFCKD_LINE + 1,
	IRFCKD_NON_UNIQUE	= IRFCKD_STANDARD + 1,
	IRFCKD_UNIQUE	= IRFCKD_NON_UNIQUE + 1
    } ;

enum IRFCDATACONVERTENUM
    {	IRFCDATACONVERT_DEFAULT	= 0,
	IRFCDATACONVERT_SETDATABEHAVIOR	= 0x1,
	IRFCDATACONVERT_GETLEN	= 0x2
    } ;

enum IRFCPROPERTIESENUM
    {	IRFCPROP_LOCAL	= 0,
	IRFCPROP_CACHED	= 0x1,
	IRFCPROP_IMPORT	= 0x2,
	IRFCPROP_EXPORT	= 0x4
    } ;
#endif

enum IRFCDATACONVERTMAP
    {	IRFCDATACONVERTMAP_DEFAULT	= 0,
	IRFCDATACONVERTMAP_AUTOMATIONONLY	= 0x2,
	IRFCDATACONVERTMAP_IDL	= 0x8,
	IRFCDATACONVERTMAP_NO_TRACE_ON_ERROR	= 0x4
    } ;


extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0000_v0_0_s_ifspec;

#ifndef __ISAPrfcITab_INTERFACE_DEFINED__
#define __ISAPrfcITab_INTERFACE_DEFINED__

/* interface ISAPrfcITab */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcITab;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AAC5D62-7DB1-11D0-ACCF-080009D213D2")
    ISAPrfcITab : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ RFC_TYPEHANDLE type,
            /* [in] */ unsigned long NbElem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateStructured( 
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ ISAPrfcStructDesc *pStructure) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadLine( 
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][out] */ byte *dest) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteLine( 
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InsertLine( 
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppendLine( 
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteLine( 
            /* [in] */ unsigned long line) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FreeLines( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LineCount( 
            /* [retval][out] */ unsigned long *plLines) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LineLength( 
            /* [retval][out] */ unsigned long *plLength) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][string][out] */ OLECHAR **ppwszName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Structure( 
            /* [retval][out] */ ISAPrfcStructDesc **ppStructure) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetView( 
            /* [in] */ ISAPrfcStructDesc *pView) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetView( 
            /* [retval][out] */ ISAPrfcStructDesc **ppView) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateStructuredEx( 
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ ISAPrfcStructDesc *pStructure,
            /* [in] */ unsigned long lItabType,
            /* [in] */ unsigned long lKeyType,
            /* [in] */ unsigned long cntKeys,
            /* [size_is][in] */ unsigned long *rglKeyIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetKey( 
            /* [out] */ unsigned long *plItabType,
            /* [out] */ unsigned long *plKeyType,
            /* [out] */ unsigned long *pcntKeys,
            /* [size_is][size_is][out] */ unsigned long **prglKeyIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcITabVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcITab * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcITab * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcITab * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            ISAPrfcITab * This,
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ RFC_TYPEHANDLE type,
            /* [in] */ unsigned long NbElem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStructured )( 
            ISAPrfcITab * This,
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ ISAPrfcStructDesc *pStructure);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadLine )( 
            ISAPrfcITab * This,
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][out] */ byte *dest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WriteLine )( 
            ISAPrfcITab * This,
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InsertLine )( 
            ISAPrfcITab * This,
            /* [in] */ unsigned long line,
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AppendLine )( 
            ISAPrfcITab * This,
            /* [in] */ unsigned long lLen,
            /* [size_is][in] */ const byte *src);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteLine )( 
            ISAPrfcITab * This,
            /* [in] */ unsigned long line);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FreeLines )( 
            ISAPrfcITab * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineCount )( 
            ISAPrfcITab * This,
            /* [retval][out] */ unsigned long *plLines);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineLength )( 
            ISAPrfcITab * This,
            /* [retval][out] */ unsigned long *plLength);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ISAPrfcITab * This,
            /* [retval][string][out] */ OLECHAR **ppwszName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Structure )( 
            ISAPrfcITab * This,
            /* [retval][out] */ ISAPrfcStructDesc **ppStructure);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetView )( 
            ISAPrfcITab * This,
            /* [in] */ ISAPrfcStructDesc *pView);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetView )( 
            ISAPrfcITab * This,
            /* [retval][out] */ ISAPrfcStructDesc **ppView);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStructuredEx )( 
            ISAPrfcITab * This,
            /* [string][in] */ const OLECHAR *name,
            /* [in] */ ISAPrfcStructDesc *pStructure,
            /* [in] */ unsigned long lItabType,
            /* [in] */ unsigned long lKeyType,
            /* [in] */ unsigned long cntKeys,
            /* [size_is][in] */ unsigned long *rglKeyIndex);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetKey )( 
            ISAPrfcITab * This,
            /* [out] */ unsigned long *plItabType,
            /* [out] */ unsigned long *plKeyType,
            /* [out] */ unsigned long *pcntKeys,
            /* [size_is][size_is][out] */ unsigned long **prglKeyIndex);
        
        END_INTERFACE
    } ISAPrfcITabVtbl;

    interface ISAPrfcITab
    {
        CONST_VTBL struct ISAPrfcITabVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcITab_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcITab_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcITab_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcITab_Create(This,name,type,NbElem)	\
    (This)->lpVtbl -> Create(This,name,type,NbElem)

#define ISAPrfcITab_CreateStructured(This,name,pStructure)	\
    (This)->lpVtbl -> CreateStructured(This,name,pStructure)

#define ISAPrfcITab_ReadLine(This,line,lLen,dest)	\
    (This)->lpVtbl -> ReadLine(This,line,lLen,dest)

#define ISAPrfcITab_WriteLine(This,line,lLen,src)	\
    (This)->lpVtbl -> WriteLine(This,line,lLen,src)

#define ISAPrfcITab_InsertLine(This,line,lLen,src)	\
    (This)->lpVtbl -> InsertLine(This,line,lLen,src)

#define ISAPrfcITab_AppendLine(This,lLen,src)	\
    (This)->lpVtbl -> AppendLine(This,lLen,src)

#define ISAPrfcITab_DeleteLine(This,line)	\
    (This)->lpVtbl -> DeleteLine(This,line)

#define ISAPrfcITab_FreeLines(This)	\
    (This)->lpVtbl -> FreeLines(This)

#define ISAPrfcITab_get_LineCount(This,plLines)	\
    (This)->lpVtbl -> get_LineCount(This,plLines)

#define ISAPrfcITab_get_LineLength(This,plLength)	\
    (This)->lpVtbl -> get_LineLength(This,plLength)

#define ISAPrfcITab_get_Name(This,ppwszName)	\
    (This)->lpVtbl -> get_Name(This,ppwszName)

#define ISAPrfcITab_get_Structure(This,ppStructure)	\
    (This)->lpVtbl -> get_Structure(This,ppStructure)

#define ISAPrfcITab_SetView(This,pView)	\
    (This)->lpVtbl -> SetView(This,pView)

#define ISAPrfcITab_GetView(This,ppView)	\
    (This)->lpVtbl -> GetView(This,ppView)

#define ISAPrfcITab_CreateStructuredEx(This,name,pStructure,lItabType,lKeyType,cntKeys,rglKeyIndex)	\
    (This)->lpVtbl -> CreateStructuredEx(This,name,pStructure,lItabType,lKeyType,cntKeys,rglKeyIndex)

#define ISAPrfcITab_GetKey(This,plItabType,plKeyType,pcntKeys,prglKeyIndex)	\
    (This)->lpVtbl -> GetKey(This,plItabType,plKeyType,pcntKeys,prglKeyIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_Create_Proxy( 
    ISAPrfcITab * This,
    /* [string][in] */ const OLECHAR *name,
    /* [in] */ RFC_TYPEHANDLE type,
    /* [in] */ unsigned long NbElem);


void __RPC_STUB ISAPrfcITab_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_CreateStructured_Proxy( 
    ISAPrfcITab * This,
    /* [string][in] */ const OLECHAR *name,
    /* [in] */ ISAPrfcStructDesc *pStructure);


void __RPC_STUB ISAPrfcITab_CreateStructured_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_ReadLine_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ unsigned long line,
    /* [in] */ unsigned long lLen,
    /* [size_is][out] */ byte *dest);


void __RPC_STUB ISAPrfcITab_ReadLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_WriteLine_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ unsigned long line,
    /* [in] */ unsigned long lLen,
    /* [size_is][in] */ const byte *src);


void __RPC_STUB ISAPrfcITab_WriteLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_InsertLine_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ unsigned long line,
    /* [in] */ unsigned long lLen,
    /* [size_is][in] */ const byte *src);


void __RPC_STUB ISAPrfcITab_InsertLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_AppendLine_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ unsigned long lLen,
    /* [size_is][in] */ const byte *src);


void __RPC_STUB ISAPrfcITab_AppendLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_DeleteLine_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ unsigned long line);


void __RPC_STUB ISAPrfcITab_DeleteLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_FreeLines_Proxy( 
    ISAPrfcITab * This);


void __RPC_STUB ISAPrfcITab_FreeLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_get_LineCount_Proxy( 
    ISAPrfcITab * This,
    /* [retval][out] */ unsigned long *plLines);


void __RPC_STUB ISAPrfcITab_get_LineCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_get_LineLength_Proxy( 
    ISAPrfcITab * This,
    /* [retval][out] */ unsigned long *plLength);


void __RPC_STUB ISAPrfcITab_get_LineLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_get_Name_Proxy( 
    ISAPrfcITab * This,
    /* [retval][string][out] */ OLECHAR **ppwszName);


void __RPC_STUB ISAPrfcITab_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_get_Structure_Proxy( 
    ISAPrfcITab * This,
    /* [retval][out] */ ISAPrfcStructDesc **ppStructure);


void __RPC_STUB ISAPrfcITab_get_Structure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_SetView_Proxy( 
    ISAPrfcITab * This,
    /* [in] */ ISAPrfcStructDesc *pView);


void __RPC_STUB ISAPrfcITab_SetView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_GetView_Proxy( 
    ISAPrfcITab * This,
    /* [retval][out] */ ISAPrfcStructDesc **ppView);


void __RPC_STUB ISAPrfcITab_GetView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_CreateStructuredEx_Proxy( 
    ISAPrfcITab * This,
    /* [string][in] */ const OLECHAR *name,
    /* [in] */ ISAPrfcStructDesc *pStructure,
    /* [in] */ unsigned long lItabType,
    /* [in] */ unsigned long lKeyType,
    /* [in] */ unsigned long cntKeys,
    /* [size_is][in] */ unsigned long *rglKeyIndex);


void __RPC_STUB ISAPrfcITab_CreateStructuredEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab_GetKey_Proxy( 
    ISAPrfcITab * This,
    /* [out] */ unsigned long *plItabType,
    /* [out] */ unsigned long *plKeyType,
    /* [out] */ unsigned long *pcntKeys,
    /* [size_is][size_is][out] */ unsigned long **prglKeyIndex);


void __RPC_STUB ISAPrfcITab_GetKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcITab_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcLocalITab_INTERFACE_DEFINED__
#define __ISAPrfcLocalITab_INTERFACE_DEFINED__

/* interface ISAPrfcLocalITab */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcLocalITab;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00D25671-CAD6-11d0-AD03-080009D213D2")
    ISAPrfcLocalITab : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLine( 
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CpyLine( 
            /* [in] */ unsigned long line,
            /* [in] */ void *dest) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PutLine( 
            /* [in] */ unsigned long line,
            /* [in] */ void *src) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InsLine( 
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AppLine( 
            /* [out] */ void **ppLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DelLine( 
            /* [in] */ unsigned long line) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GupLine( 
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Free( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Fill( 
            /* [retval][out] */ unsigned long *plRowCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Leng( 
            /* [retval][out] */ unsigned long *plRowLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcLocalITabVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcLocalITab * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcLocalITab * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcLocalITab * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CpyLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line,
            /* [in] */ void *dest);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PutLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line,
            /* [in] */ void *src);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InsLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AppLine )( 
            ISAPrfcLocalITab * This,
            /* [out] */ void **ppLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DelLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GupLine )( 
            ISAPrfcLocalITab * This,
            /* [in] */ unsigned long line,
            /* [out] */ void **ppLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Free )( 
            ISAPrfcLocalITab * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Fill )( 
            ISAPrfcLocalITab * This,
            /* [retval][out] */ unsigned long *plRowCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Leng )( 
            ISAPrfcLocalITab * This,
            /* [retval][out] */ unsigned long *plRowLength);
        
        END_INTERFACE
    } ISAPrfcLocalITabVtbl;

    interface ISAPrfcLocalITab
    {
        CONST_VTBL struct ISAPrfcLocalITabVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcLocalITab_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcLocalITab_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcLocalITab_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcLocalITab_GetLine(This,line,ppLine)	\
    (This)->lpVtbl -> GetLine(This,line,ppLine)

#define ISAPrfcLocalITab_CpyLine(This,line,dest)	\
    (This)->lpVtbl -> CpyLine(This,line,dest)

#define ISAPrfcLocalITab_PutLine(This,line,src)	\
    (This)->lpVtbl -> PutLine(This,line,src)

#define ISAPrfcLocalITab_InsLine(This,line,ppLine)	\
    (This)->lpVtbl -> InsLine(This,line,ppLine)

#define ISAPrfcLocalITab_AppLine(This,ppLine)	\
    (This)->lpVtbl -> AppLine(This,ppLine)

#define ISAPrfcLocalITab_DelLine(This,line)	\
    (This)->lpVtbl -> DelLine(This,line)

#define ISAPrfcLocalITab_GupLine(This,line,ppLine)	\
    (This)->lpVtbl -> GupLine(This,line,ppLine)

#define ISAPrfcLocalITab_Free(This)	\
    (This)->lpVtbl -> Free(This)

#define ISAPrfcLocalITab_Fill(This,plRowCount)	\
    (This)->lpVtbl -> Fill(This,plRowCount)

#define ISAPrfcLocalITab_Leng(This,plRowLength)	\
    (This)->lpVtbl -> Leng(This,plRowLength)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_GetLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line,
    /* [out] */ void **ppLine);


void __RPC_STUB ISAPrfcLocalITab_GetLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_CpyLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line,
    /* [in] */ void *dest);


void __RPC_STUB ISAPrfcLocalITab_CpyLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_PutLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line,
    /* [in] */ void *src);


void __RPC_STUB ISAPrfcLocalITab_PutLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_InsLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line,
    /* [out] */ void **ppLine);


void __RPC_STUB ISAPrfcLocalITab_InsLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_AppLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [out] */ void **ppLine);


void __RPC_STUB ISAPrfcLocalITab_AppLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_DelLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line);


void __RPC_STUB ISAPrfcLocalITab_DelLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_GupLine_Proxy( 
    ISAPrfcLocalITab * This,
    /* [in] */ unsigned long line,
    /* [out] */ void **ppLine);


void __RPC_STUB ISAPrfcLocalITab_GupLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_Free_Proxy( 
    ISAPrfcLocalITab * This);


void __RPC_STUB ISAPrfcLocalITab_Free_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_Fill_Proxy( 
    ISAPrfcLocalITab * This,
    /* [retval][out] */ unsigned long *plRowCount);


void __RPC_STUB ISAPrfcLocalITab_Fill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcLocalITab_Leng_Proxy( 
    ISAPrfcLocalITab * This,
    /* [retval][out] */ unsigned long *plRowLength);


void __RPC_STUB ISAPrfcLocalITab_Leng_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcLocalITab_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapirfc_0122 */
/* [local] */ 

typedef void *ITAB_H;



extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0122_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0122_v0_0_s_ifspec;

#ifndef __ISAPrfcITabHandleAccess_INTERFACE_DEFINED__
#define __ISAPrfcITabHandleAccess_INTERFACE_DEFINED__

/* interface ISAPrfcITabHandleAccess */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcITabHandleAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2EE96A1-4542-11d1-AD41-080009D213D2")
    ISAPrfcITabHandleAccess : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHandle( 
            /* [out] */ ITAB_H *phITab) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AttachItab( 
            /* [in] */ ITAB_H hITab,
            /* [in] */ ISAPrfcStructDesc *pStrDesc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DetachItab( 
            /* [out] */ ITAB_H *phITab) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcITabHandleAccessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcITabHandleAccess * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcITabHandleAccess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcITabHandleAccess * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHandle )( 
            ISAPrfcITabHandleAccess * This,
            /* [out] */ ITAB_H *phITab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AttachItab )( 
            ISAPrfcITabHandleAccess * This,
            /* [in] */ ITAB_H hITab,
            /* [in] */ ISAPrfcStructDesc *pStrDesc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DetachItab )( 
            ISAPrfcITabHandleAccess * This,
            /* [out] */ ITAB_H *phITab);
        
        END_INTERFACE
    } ISAPrfcITabHandleAccessVtbl;

    interface ISAPrfcITabHandleAccess
    {
        CONST_VTBL struct ISAPrfcITabHandleAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcITabHandleAccess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcITabHandleAccess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcITabHandleAccess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcITabHandleAccess_GetHandle(This,phITab)	\
    (This)->lpVtbl -> GetHandle(This,phITab)

#define ISAPrfcITabHandleAccess_AttachItab(This,hITab,pStrDesc)	\
    (This)->lpVtbl -> AttachItab(This,hITab,pStrDesc)

#define ISAPrfcITabHandleAccess_DetachItab(This,phITab)	\
    (This)->lpVtbl -> DetachItab(This,phITab)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITabHandleAccess_GetHandle_Proxy( 
    ISAPrfcITabHandleAccess * This,
    /* [out] */ ITAB_H *phITab);


void __RPC_STUB ISAPrfcITabHandleAccess_GetHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITabHandleAccess_AttachItab_Proxy( 
    ISAPrfcITabHandleAccess * This,
    /* [in] */ ITAB_H hITab,
    /* [in] */ ISAPrfcStructDesc *pStrDesc);


void __RPC_STUB ISAPrfcITabHandleAccess_AttachItab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITabHandleAccess_DetachItab_Proxy( 
    ISAPrfcITabHandleAccess * This,
    /* [out] */ ITAB_H *phITab);


void __RPC_STUB ISAPrfcITabHandleAccess_DetachItab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcITabHandleAccess_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcStructDesc_INTERFACE_DEFINED__
#define __ISAPrfcStructDesc_INTERFACE_DEFINED__

/* interface ISAPrfcStructDesc */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcStructDesc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AAC5D66-7DB1-11D0-ACCF-080009D213D2")
    ISAPrfcStructDesc : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFields( 
            /* [in] */ unsigned long cntFields,
            /* [size_is][in] */ const RFC_TYPE_ELEMENT_IN *pFields) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddField( 
            /* [string][in] */ const OLECHAR *wszName,
            /* [in] */ RFC_TYPEHANDLE Type,
            /* [in] */ unsigned long Length,
            /* [in] */ unsigned long Decimals,
            /* [in] */ ISAPrfcStructDesc *pStru) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetField( 
            /* [in] */ unsigned long FieldNo,
            /* [size_is][out][string] */ OLECHAR *wszName,
            /* [in] */ unsigned long lMaxLen,
            /* [out] */ RFC_TYPEHANDLE *pType,
            /* [out] */ unsigned long *pLength,
            /* [out] */ unsigned long *pDecimal,
            /* [out] */ unsigned long *pOffset,
            /* [out] */ ISAPrfcStructDesc **pStru) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFields( 
            /* [out] */ unsigned long *pcntUsed,
            /* [size_is][size_is][out] */ RFC_TYPE_ELEMENT_OUT **ppTout,
            /* [size_is][size_is][out] */ OLECHAR **ppBuf,
            /* [out] */ unsigned long *pBuffMax) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSpace( 
            /* [size_is][out][in] */ byte *line,
            /* [in] */ long cntBytes) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Lock( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in][string] */ const OLECHAR *szName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][string][out] */ OLECHAR **ppwszName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ unsigned long *pCount) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ unsigned long *pLen) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Alignment( 
            /* [retval][out] */ unsigned long *pAlign) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsAlpha( 
            /* [retval][out] */ BOOL *pIsAlpha) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsLocked( 
            /* [retval][out] */ BOOL *pIsLocked) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsNested( 
            /* [retval][out] */ BOOL *pIsNested) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetGuid( 
            /* [in] */ const IID *riid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGuid( 
            /* [out] */ IID *riid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcStructDescVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcStructDesc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcStructDesc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcStructDesc * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFields )( 
            ISAPrfcStructDesc * This,
            /* [in] */ unsigned long cntFields,
            /* [size_is][in] */ const RFC_TYPE_ELEMENT_IN *pFields);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddField )( 
            ISAPrfcStructDesc * This,
            /* [string][in] */ const OLECHAR *wszName,
            /* [in] */ RFC_TYPEHANDLE Type,
            /* [in] */ unsigned long Length,
            /* [in] */ unsigned long Decimals,
            /* [in] */ ISAPrfcStructDesc *pStru);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetField )( 
            ISAPrfcStructDesc * This,
            /* [in] */ unsigned long FieldNo,
            /* [size_is][out][string] */ OLECHAR *wszName,
            /* [in] */ unsigned long lMaxLen,
            /* [out] */ RFC_TYPEHANDLE *pType,
            /* [out] */ unsigned long *pLength,
            /* [out] */ unsigned long *pDecimal,
            /* [out] */ unsigned long *pOffset,
            /* [out] */ ISAPrfcStructDesc **pStru);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFields )( 
            ISAPrfcStructDesc * This,
            /* [out] */ unsigned long *pcntUsed,
            /* [size_is][size_is][out] */ RFC_TYPE_ELEMENT_OUT **ppTout,
            /* [size_is][size_is][out] */ OLECHAR **ppBuf,
            /* [out] */ unsigned long *pBuffMax);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSpace )( 
            ISAPrfcStructDesc * This,
            /* [size_is][out][in] */ byte *line,
            /* [in] */ long cntBytes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Lock )( 
            ISAPrfcStructDesc * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            ISAPrfcStructDesc * This,
            /* [in][string] */ const OLECHAR *szName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ISAPrfcStructDesc * This,
            /* [retval][string][out] */ OLECHAR **ppwszName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ unsigned long *pCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ unsigned long *pLen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Alignment )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ unsigned long *pAlign);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsAlpha )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ BOOL *pIsAlpha);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLocked )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ BOOL *pIsLocked);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsNested )( 
            ISAPrfcStructDesc * This,
            /* [retval][out] */ BOOL *pIsNested);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetGuid )( 
            ISAPrfcStructDesc * This,
            /* [in] */ const IID *riid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGuid )( 
            ISAPrfcStructDesc * This,
            /* [out] */ IID *riid);
        
        END_INTERFACE
    } ISAPrfcStructDescVtbl;

    interface ISAPrfcStructDesc
    {
        CONST_VTBL struct ISAPrfcStructDescVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcStructDesc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcStructDesc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcStructDesc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcStructDesc_SetFields(This,cntFields,pFields)	\
    (This)->lpVtbl -> SetFields(This,cntFields,pFields)

#define ISAPrfcStructDesc_AddField(This,wszName,Type,Length,Decimals,pStru)	\
    (This)->lpVtbl -> AddField(This,wszName,Type,Length,Decimals,pStru)

#define ISAPrfcStructDesc_GetField(This,FieldNo,wszName,lMaxLen,pType,pLength,pDecimal,pOffset,pStru)	\
    (This)->lpVtbl -> GetField(This,FieldNo,wszName,lMaxLen,pType,pLength,pDecimal,pOffset,pStru)

#define ISAPrfcStructDesc_GetFields(This,pcntUsed,ppTout,ppBuf,pBuffMax)	\
    (This)->lpVtbl -> GetFields(This,pcntUsed,ppTout,ppBuf,pBuffMax)

#define ISAPrfcStructDesc_SetSpace(This,line,cntBytes)	\
    (This)->lpVtbl -> SetSpace(This,line,cntBytes)

#define ISAPrfcStructDesc_Lock(This)	\
    (This)->lpVtbl -> Lock(This)

#define ISAPrfcStructDesc_SetName(This,szName)	\
    (This)->lpVtbl -> SetName(This,szName)

#define ISAPrfcStructDesc_GetName(This,ppwszName)	\
    (This)->lpVtbl -> GetName(This,ppwszName)

#define ISAPrfcStructDesc_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#define ISAPrfcStructDesc_get_Length(This,pLen)	\
    (This)->lpVtbl -> get_Length(This,pLen)

#define ISAPrfcStructDesc_get_Alignment(This,pAlign)	\
    (This)->lpVtbl -> get_Alignment(This,pAlign)

#define ISAPrfcStructDesc_get_IsAlpha(This,pIsAlpha)	\
    (This)->lpVtbl -> get_IsAlpha(This,pIsAlpha)

#define ISAPrfcStructDesc_get_IsLocked(This,pIsLocked)	\
    (This)->lpVtbl -> get_IsLocked(This,pIsLocked)

#define ISAPrfcStructDesc_get_IsNested(This,pIsNested)	\
    (This)->lpVtbl -> get_IsNested(This,pIsNested)

#define ISAPrfcStructDesc_SetGuid(This,riid)	\
    (This)->lpVtbl -> SetGuid(This,riid)

#define ISAPrfcStructDesc_GetGuid(This,riid)	\
    (This)->lpVtbl -> GetGuid(This,riid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_SetFields_Proxy( 
    ISAPrfcStructDesc * This,
    /* [in] */ unsigned long cntFields,
    /* [size_is][in] */ const RFC_TYPE_ELEMENT_IN *pFields);


void __RPC_STUB ISAPrfcStructDesc_SetFields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_AddField_Proxy( 
    ISAPrfcStructDesc * This,
    /* [string][in] */ const OLECHAR *wszName,
    /* [in] */ RFC_TYPEHANDLE Type,
    /* [in] */ unsigned long Length,
    /* [in] */ unsigned long Decimals,
    /* [in] */ ISAPrfcStructDesc *pStru);


void __RPC_STUB ISAPrfcStructDesc_AddField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_GetField_Proxy( 
    ISAPrfcStructDesc * This,
    /* [in] */ unsigned long FieldNo,
    /* [size_is][out][string] */ OLECHAR *wszName,
    /* [in] */ unsigned long lMaxLen,
    /* [out] */ RFC_TYPEHANDLE *pType,
    /* [out] */ unsigned long *pLength,
    /* [out] */ unsigned long *pDecimal,
    /* [out] */ unsigned long *pOffset,
    /* [out] */ ISAPrfcStructDesc **pStru);


void __RPC_STUB ISAPrfcStructDesc_GetField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_GetFields_Proxy( 
    ISAPrfcStructDesc * This,
    /* [out] */ unsigned long *pcntUsed,
    /* [size_is][size_is][out] */ RFC_TYPE_ELEMENT_OUT **ppTout,
    /* [size_is][size_is][out] */ OLECHAR **ppBuf,
    /* [out] */ unsigned long *pBuffMax);


void __RPC_STUB ISAPrfcStructDesc_GetFields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_SetSpace_Proxy( 
    ISAPrfcStructDesc * This,
    /* [size_is][out][in] */ byte *line,
    /* [in] */ long cntBytes);


void __RPC_STUB ISAPrfcStructDesc_SetSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_Lock_Proxy( 
    ISAPrfcStructDesc * This);


void __RPC_STUB ISAPrfcStructDesc_Lock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_SetName_Proxy( 
    ISAPrfcStructDesc * This,
    /* [in][string] */ const OLECHAR *szName);


void __RPC_STUB ISAPrfcStructDesc_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_GetName_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][string][out] */ OLECHAR **ppwszName);


void __RPC_STUB ISAPrfcStructDesc_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_Count_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ unsigned long *pCount);


void __RPC_STUB ISAPrfcStructDesc_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_Length_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ unsigned long *pLen);


void __RPC_STUB ISAPrfcStructDesc_get_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_Alignment_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ unsigned long *pAlign);


void __RPC_STUB ISAPrfcStructDesc_get_Alignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_IsAlpha_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ BOOL *pIsAlpha);


void __RPC_STUB ISAPrfcStructDesc_get_IsAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_IsLocked_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ BOOL *pIsLocked);


void __RPC_STUB ISAPrfcStructDesc_get_IsLocked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_get_IsNested_Proxy( 
    ISAPrfcStructDesc * This,
    /* [retval][out] */ BOOL *pIsNested);


void __RPC_STUB ISAPrfcStructDesc_get_IsNested_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_SetGuid_Proxy( 
    ISAPrfcStructDesc * This,
    /* [in] */ const IID *riid);


void __RPC_STUB ISAPrfcStructDesc_SetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructDesc_GetGuid_Proxy( 
    ISAPrfcStructDesc * This,
    /* [out] */ IID *riid);


void __RPC_STUB ISAPrfcStructDesc_GetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcStructDesc_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcStructHandleAccess_INTERFACE_DEFINED__
#define __ISAPrfcStructHandleAccess_INTERFACE_DEFINED__

/* interface ISAPrfcStructHandleAccess */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcStructHandleAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2EE96A3-4542-11d1-AD41-080009D213D2")
    ISAPrfcStructHandleAccess : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHandle( 
            /* [out] */ RFC_TYPEHANDLE *pHandle) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateFromHandle( 
            /* [in] */ RFC_TYPEHANDLE Handle) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcStructHandleAccessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcStructHandleAccess * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcStructHandleAccess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcStructHandleAccess * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHandle )( 
            ISAPrfcStructHandleAccess * This,
            /* [out] */ RFC_TYPEHANDLE *pHandle);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateFromHandle )( 
            ISAPrfcStructHandleAccess * This,
            /* [in] */ RFC_TYPEHANDLE Handle);
        
        END_INTERFACE
    } ISAPrfcStructHandleAccessVtbl;

    interface ISAPrfcStructHandleAccess
    {
        CONST_VTBL struct ISAPrfcStructHandleAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcStructHandleAccess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcStructHandleAccess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcStructHandleAccess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcStructHandleAccess_GetHandle(This,pHandle)	\
    (This)->lpVtbl -> GetHandle(This,pHandle)

#define ISAPrfcStructHandleAccess_CreateFromHandle(This,Handle)	\
    (This)->lpVtbl -> CreateFromHandle(This,Handle)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructHandleAccess_GetHandle_Proxy( 
    ISAPrfcStructHandleAccess * This,
    /* [out] */ RFC_TYPEHANDLE *pHandle);


void __RPC_STUB ISAPrfcStructHandleAccess_GetHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructHandleAccess_CreateFromHandle_Proxy( 
    ISAPrfcStructHandleAccess * This,
    /* [in] */ RFC_TYPEHANDLE Handle);


void __RPC_STUB ISAPrfcStructHandleAccess_CreateFromHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcStructHandleAccess_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcStructView_INTERFACE_DEFINED__
#define __ISAPrfcStructView_INTERFACE_DEFINED__

/* interface ISAPrfcStructView */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcStructView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AAC5D6B-7DB1-11D0-ACCF-080009D213D2")
    ISAPrfcStructView : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AttachRFC_FIELDTable( 
            /* [in] */ ISAPrfcITab *pItab) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RFC_FIELDTable( 
            /* [retval][out] */ ISAPrfcITab **ppItab) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcStructViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcStructView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcStructView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcStructView * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AttachRFC_FIELDTable )( 
            ISAPrfcStructView * This,
            /* [in] */ ISAPrfcITab *pItab);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RFC_FIELDTable )( 
            ISAPrfcStructView * This,
            /* [retval][out] */ ISAPrfcITab **ppItab);
        
        END_INTERFACE
    } ISAPrfcStructViewVtbl;

    interface ISAPrfcStructView
    {
        CONST_VTBL struct ISAPrfcStructViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcStructView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcStructView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcStructView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcStructView_AttachRFC_FIELDTable(This,pItab)	\
    (This)->lpVtbl -> AttachRFC_FIELDTable(This,pItab)

#define ISAPrfcStructView_get_RFC_FIELDTable(This,ppItab)	\
    (This)->lpVtbl -> get_RFC_FIELDTable(This,ppItab)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructView_AttachRFC_FIELDTable_Proxy( 
    ISAPrfcStructView * This,
    /* [in] */ ISAPrfcITab *pItab);


void __RPC_STUB ISAPrfcStructView_AttachRFC_FIELDTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISAPrfcStructView_get_RFC_FIELDTable_Proxy( 
    ISAPrfcStructView * This,
    /* [retval][out] */ ISAPrfcITab **ppItab);


void __RPC_STUB ISAPrfcStructView_get_RFC_FIELDTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcStructView_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcDataConvert_INTERFACE_DEFINED__
#define __ISAPrfcDataConvert_INTERFACE_DEFINED__

/* interface ISAPrfcDataConvert */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcDataConvert;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18D30461-90A9-11d0-ACDB-080009D213D2")
    ISAPrfcDataConvert : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DataConvert( 
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType,
            /* [in] */ ULONG cbSrcLength,
            /* [in][out] */ ULONG *pcbDstLength,
            /* [in][size_is] */ BYTE *pSrc,
            /* [out][length_is][size_is] */ BYTE *pDst,
            /* [in] */ ULONG cbDstMaxLength,
            /* [in] */ DWORD dbsSrcStatus,
            /* [out] */ DWORD *pdbsStatus,
            /* [in] */ BYTE bPrecision,
            /* [in] */ BYTE bScale,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanConvert( 
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionSize( 
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType,
            /* [in] */ ULONG *pcbSrcLength,
            /* [out] */ ULONG *pcbDstLength,
            /* [in][size_is] */ BYTE *pSrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapRFCTypes2OLEDBTypes( 
            /* [in] */ RFC_TYPE_ELEMENT_OUT *pRfcT,
            /* [out] */ WORD *pDBT,
            /* [out] */ ULONG *pColumnSize,
            /* [out] */ BYTE *pPrecision,
            /* [out] */ BYTE *pScale,
            /* [in] */ ULONG dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapOLEDBTypes2RFCTypes( 
            /* [in] */ WORD DBT,
            /* [in] */ WORD Length,
            /* [in] */ WORD Precision,
            /* [in] */ WORD Scale,
            /* [out] */ RFC_TYPEHANDLE *pRFCT,
            /* [out] */ ULONG *pColumnSize,
            /* [out] */ BYTE *pScale,
            /* [in] */ ULONG dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcDataConvertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcDataConvert * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcDataConvert * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcDataConvert * This);
        
        HRESULT ( STDMETHODCALLTYPE *DataConvert )( 
            ISAPrfcDataConvert * This,
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType,
            /* [in] */ ULONG cbSrcLength,
            /* [in][out] */ ULONG *pcbDstLength,
            /* [in][size_is] */ BYTE *pSrc,
            /* [out][length_is][size_is] */ BYTE *pDst,
            /* [in] */ ULONG cbDstMaxLength,
            /* [in] */ DWORD dbsSrcStatus,
            /* [out] */ DWORD *pdbsStatus,
            /* [in] */ BYTE bPrecision,
            /* [in] */ BYTE bScale,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *CanConvert )( 
            ISAPrfcDataConvert * This,
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionSize )( 
            ISAPrfcDataConvert * This,
            /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
            /* [in] */ PCIRFCTYPE_CONVERT pDstType,
            /* [in] */ ULONG *pcbSrcLength,
            /* [out] */ ULONG *pcbDstLength,
            /* [in][size_is] */ BYTE *pSrc);
        
        HRESULT ( STDMETHODCALLTYPE *MapRFCTypes2OLEDBTypes )( 
            ISAPrfcDataConvert * This,
            /* [in] */ RFC_TYPE_ELEMENT_OUT *pRfcT,
            /* [out] */ WORD *pDBT,
            /* [out] */ ULONG *pColumnSize,
            /* [out] */ BYTE *pPrecision,
            /* [out] */ BYTE *pScale,
            /* [in] */ ULONG dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *MapOLEDBTypes2RFCTypes )( 
            ISAPrfcDataConvert * This,
            /* [in] */ WORD DBT,
            /* [in] */ WORD Length,
            /* [in] */ WORD Precision,
            /* [in] */ WORD Scale,
            /* [out] */ RFC_TYPEHANDLE *pRFCT,
            /* [out] */ ULONG *pColumnSize,
            /* [out] */ BYTE *pScale,
            /* [in] */ ULONG dwFlags);
        
        END_INTERFACE
    } ISAPrfcDataConvertVtbl;

    interface ISAPrfcDataConvert
    {
        CONST_VTBL struct ISAPrfcDataConvertVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcDataConvert_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcDataConvert_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcDataConvert_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcDataConvert_DataConvert(This,pSrcType,pDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)	\
    (This)->lpVtbl -> DataConvert(This,pSrcType,pDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)

#define ISAPrfcDataConvert_CanConvert(This,pSrcType,pDstType)	\
    (This)->lpVtbl -> CanConvert(This,pSrcType,pDstType)

#define ISAPrfcDataConvert_GetConversionSize(This,pSrcType,pDstType,pcbSrcLength,pcbDstLength,pSrc)	\
    (This)->lpVtbl -> GetConversionSize(This,pSrcType,pDstType,pcbSrcLength,pcbDstLength,pSrc)

#define ISAPrfcDataConvert_MapRFCTypes2OLEDBTypes(This,pRfcT,pDBT,pColumnSize,pPrecision,pScale,dwFlags)	\
    (This)->lpVtbl -> MapRFCTypes2OLEDBTypes(This,pRfcT,pDBT,pColumnSize,pPrecision,pScale,dwFlags)

#define ISAPrfcDataConvert_MapOLEDBTypes2RFCTypes(This,DBT,Length,Precision,Scale,pRFCT,pColumnSize,pScale,dwFlags)	\
    (This)->lpVtbl -> MapOLEDBTypes2RFCTypes(This,DBT,Length,Precision,Scale,pRFCT,pColumnSize,pScale,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISAPrfcDataConvert_DataConvert_Proxy( 
    ISAPrfcDataConvert * This,
    /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
    /* [in] */ PCIRFCTYPE_CONVERT pDstType,
    /* [in] */ ULONG cbSrcLength,
    /* [in][out] */ ULONG *pcbDstLength,
    /* [in][size_is] */ BYTE *pSrc,
    /* [out][length_is][size_is] */ BYTE *pDst,
    /* [in] */ ULONG cbDstMaxLength,
    /* [in] */ DWORD dbsSrcStatus,
    /* [out] */ DWORD *pdbsStatus,
    /* [in] */ BYTE bPrecision,
    /* [in] */ BYTE bScale,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB ISAPrfcDataConvert_DataConvert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcDataConvert_CanConvert_Proxy( 
    ISAPrfcDataConvert * This,
    /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
    /* [in] */ PCIRFCTYPE_CONVERT pDstType);


void __RPC_STUB ISAPrfcDataConvert_CanConvert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcDataConvert_GetConversionSize_Proxy( 
    ISAPrfcDataConvert * This,
    /* [in] */ PCIRFCTYPE_CONVERT pSrcType,
    /* [in] */ PCIRFCTYPE_CONVERT pDstType,
    /* [in] */ ULONG *pcbSrcLength,
    /* [out] */ ULONG *pcbDstLength,
    /* [in][size_is] */ BYTE *pSrc);


void __RPC_STUB ISAPrfcDataConvert_GetConversionSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcDataConvert_MapRFCTypes2OLEDBTypes_Proxy( 
    ISAPrfcDataConvert * This,
    /* [in] */ RFC_TYPE_ELEMENT_OUT *pRfcT,
    /* [out] */ WORD *pDBT,
    /* [out] */ ULONG *pColumnSize,
    /* [out] */ BYTE *pPrecision,
    /* [out] */ BYTE *pScale,
    /* [in] */ ULONG dwFlags);


void __RPC_STUB ISAPrfcDataConvert_MapRFCTypes2OLEDBTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcDataConvert_MapOLEDBTypes2RFCTypes_Proxy( 
    ISAPrfcDataConvert * This,
    /* [in] */ WORD DBT,
    /* [in] */ WORD Length,
    /* [in] */ WORD Precision,
    /* [in] */ WORD Scale,
    /* [out] */ RFC_TYPEHANDLE *pRFCT,
    /* [out] */ ULONG *pColumnSize,
    /* [out] */ BYTE *pScale,
    /* [in] */ ULONG dwFlags);


void __RPC_STUB ISAPrfcDataConvert_MapOLEDBTypes2RFCTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcDataConvert_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcITab2Recordset_INTERFACE_DEFINED__
#define __ISAPrfcITab2Recordset_INTERFACE_DEFINED__

/* interface ISAPrfcITab2Recordset */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcITab2Recordset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C45992A2-08CD-11d1-AD2E-080009D213D2")
    ISAPrfcITab2Recordset : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRecordset( 
            /* [in] */ DWORD dwProp,
            /* [out] */ IDispatch **ppRecordset) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UpdateFromRecordset( 
            /* [in] */ DWORD dwOption,
            /* [in] */ IUnknown *pRecordset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcITab2RecordsetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcITab2Recordset * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcITab2Recordset * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcITab2Recordset * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRecordset )( 
            ISAPrfcITab2Recordset * This,
            /* [in] */ DWORD dwProp,
            /* [out] */ IDispatch **ppRecordset);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UpdateFromRecordset )( 
            ISAPrfcITab2Recordset * This,
            /* [in] */ DWORD dwOption,
            /* [in] */ IUnknown *pRecordset);
        
        END_INTERFACE
    } ISAPrfcITab2RecordsetVtbl;

    interface ISAPrfcITab2Recordset
    {
        CONST_VTBL struct ISAPrfcITab2RecordsetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcITab2Recordset_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcITab2Recordset_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcITab2Recordset_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcITab2Recordset_GetRecordset(This,dwProp,ppRecordset)	\
    (This)->lpVtbl -> GetRecordset(This,dwProp,ppRecordset)

#define ISAPrfcITab2Recordset_UpdateFromRecordset(This,dwOption,pRecordset)	\
    (This)->lpVtbl -> UpdateFromRecordset(This,dwOption,pRecordset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab2Recordset_GetRecordset_Proxy( 
    ISAPrfcITab2Recordset * This,
    /* [in] */ DWORD dwProp,
    /* [out] */ IDispatch **ppRecordset);


void __RPC_STUB ISAPrfcITab2Recordset_GetRecordset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcITab2Recordset_UpdateFromRecordset_Proxy( 
    ISAPrfcITab2Recordset * This,
    /* [in] */ DWORD dwOption,
    /* [in] */ IUnknown *pRecordset);


void __RPC_STUB ISAPrfcITab2Recordset_UpdateFromRecordset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcITab2Recordset_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcStruct2OLEDB_INTERFACE_DEFINED__
#define __ISAPrfcStruct2OLEDB_INTERFACE_DEFINED__

/* interface ISAPrfcStruct2OLEDB */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcStruct2OLEDB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51E877C1-072C-11d1-AEB5-00A024AFE7E1")
    ISAPrfcStruct2OLEDB : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetBindings( 
            /* [in] */ boolean bAutomationOnly,
            /* [out] */ ULONG *pulNeededHead,
            /* [out] */ ULONG *pulLen,
            /* [out] */ ULONG *pcntFields,
            /* [size_is][size_is][out] */ void **ppBindings) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateFromBindings( 
            /* [in] */ DWORD dwOption,
            /* [in] */ IUnknown *piRowset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcStruct2OLEDBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcStruct2OLEDB * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcStruct2OLEDB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcStruct2OLEDB * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetBindings )( 
            ISAPrfcStruct2OLEDB * This,
            /* [in] */ boolean bAutomationOnly,
            /* [out] */ ULONG *pulNeededHead,
            /* [out] */ ULONG *pulLen,
            /* [out] */ ULONG *pcntFields,
            /* [size_is][size_is][out] */ void **ppBindings);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateFromBindings )( 
            ISAPrfcStruct2OLEDB * This,
            /* [in] */ DWORD dwOption,
            /* [in] */ IUnknown *piRowset);
        
        END_INTERFACE
    } ISAPrfcStruct2OLEDBVtbl;

    interface ISAPrfcStruct2OLEDB
    {
        CONST_VTBL struct ISAPrfcStruct2OLEDBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcStruct2OLEDB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcStruct2OLEDB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcStruct2OLEDB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcStruct2OLEDB_GetBindings(This,bAutomationOnly,pulNeededHead,pulLen,pcntFields,ppBindings)	\
    (This)->lpVtbl -> GetBindings(This,bAutomationOnly,pulNeededHead,pulLen,pcntFields,ppBindings)

#define ISAPrfcStruct2OLEDB_CreateFromBindings(This,dwOption,piRowset)	\
    (This)->lpVtbl -> CreateFromBindings(This,dwOption,piRowset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStruct2OLEDB_GetBindings_Proxy( 
    ISAPrfcStruct2OLEDB * This,
    /* [in] */ boolean bAutomationOnly,
    /* [out] */ ULONG *pulNeededHead,
    /* [out] */ ULONG *pulLen,
    /* [out] */ ULONG *pcntFields,
    /* [size_is][size_is][out] */ void **ppBindings);


void __RPC_STUB ISAPrfcStruct2OLEDB_GetBindings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStruct2OLEDB_CreateFromBindings_Proxy( 
    ISAPrfcStruct2OLEDB * This,
    /* [in] */ DWORD dwOption,
    /* [in] */ IUnknown *piRowset);


void __RPC_STUB ISAPrfcStruct2OLEDB_CreateFromBindings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcStruct2OLEDB_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcStruct2OLEDBHinted_INTERFACE_DEFINED__
#define __ISAPrfcStruct2OLEDBHinted_INTERFACE_DEFINED__

/* interface ISAPrfcStruct2OLEDBHinted */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISAPrfcStruct2OLEDBHinted;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAB20CA5-B71F-4b1e-A32D-685015A2B357")
    ISAPrfcStruct2OLEDBHinted : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEducatedBindings( 
            /* [in] */ IUnknown *piSrcRowset,
            /* [in] */ boolean bAutomationOnly,
            /* [out] */ ULONG *pulNeededHead,
            /* [out] */ ULONG *pulLen,
            /* [out] */ ULONG *pcntFields,
            /* [size_is][size_is][out] */ void **ppBindings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcStruct2OLEDBHintedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcStruct2OLEDBHinted * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcStruct2OLEDBHinted * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcStruct2OLEDBHinted * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEducatedBindings )( 
            ISAPrfcStruct2OLEDBHinted * This,
            /* [in] */ IUnknown *piSrcRowset,
            /* [in] */ boolean bAutomationOnly,
            /* [out] */ ULONG *pulNeededHead,
            /* [out] */ ULONG *pulLen,
            /* [out] */ ULONG *pcntFields,
            /* [size_is][size_is][out] */ void **ppBindings);
        
        END_INTERFACE
    } ISAPrfcStruct2OLEDBHintedVtbl;

    interface ISAPrfcStruct2OLEDBHinted
    {
        CONST_VTBL struct ISAPrfcStruct2OLEDBHintedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcStruct2OLEDBHinted_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcStruct2OLEDBHinted_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcStruct2OLEDBHinted_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcStruct2OLEDBHinted_GetEducatedBindings(This,piSrcRowset,bAutomationOnly,pulNeededHead,pulLen,pcntFields,ppBindings)	\
    (This)->lpVtbl -> GetEducatedBindings(This,piSrcRowset,bAutomationOnly,pulNeededHead,pulLen,pcntFields,ppBindings)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcStruct2OLEDBHinted_GetEducatedBindings_Proxy( 
    ISAPrfcStruct2OLEDBHinted * This,
    /* [in] */ IUnknown *piSrcRowset,
    /* [in] */ boolean bAutomationOnly,
    /* [out] */ ULONG *pulNeededHead,
    /* [out] */ ULONG *pulLen,
    /* [out] */ ULONG *pcntFields,
    /* [size_is][size_is][out] */ void **ppBindings);


void __RPC_STUB ISAPrfcStruct2OLEDBHinted_GetEducatedBindings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcStruct2OLEDBHinted_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapirfc_0138 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  SAP AG
//  Systeme, Anwendungen und Produkte in der Datenverarbeitung
//  (C) Copyright SAP AG 1997 - 1998.
//
//--------------------------------------------------------------------------
//@(#) $Id: //bas/640_REL/src/krn/rfc/sapbind.idl#1 $ SAP


extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0138_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0138_v0_0_s_ifspec;

#ifndef __ISAPrfcBind_INTERFACE_DEFINED__
#define __ISAPrfcBind_INTERFACE_DEFINED__

/* interface ISAPrfcBind */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcBind;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ADF7E1A4-2750-11D1-9162-080009D213D2")
    ISAPrfcBind : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRfcHandle( 
            unsigned long handle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurrogateProcessId( 
            /* [out] */ unsigned long *pProcessId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRfcContext( 
            IUnknown *pRfcContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseRfcContext( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRfcSession( 
            IUnknown *pSession,
            unsigned long lCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRfcContext( 
            /* [out] */ IUnknown **ppRfcContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetComplete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAbort( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableCommit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearInvalidRef( 
            unsigned long lCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcBindVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcBind * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcBind * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcBind * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetRfcHandle )( 
            ISAPrfcBind * This,
            unsigned long handle);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurrogateProcessId )( 
            ISAPrfcBind * This,
            /* [out] */ unsigned long *pProcessId);
        
        HRESULT ( STDMETHODCALLTYPE *SetRfcContext )( 
            ISAPrfcBind * This,
            IUnknown *pRfcContext);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseRfcContext )( 
            ISAPrfcBind * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetRfcSession )( 
            ISAPrfcBind * This,
            IUnknown *pSession,
            unsigned long lCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetRfcContext )( 
            ISAPrfcBind * This,
            /* [out] */ IUnknown **ppRfcContext);
        
        HRESULT ( STDMETHODCALLTYPE *SetComplete )( 
            ISAPrfcBind * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAbort )( 
            ISAPrfcBind * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnableCommit )( 
            ISAPrfcBind * This);
        
        HRESULT ( STDMETHODCALLTYPE *ClearInvalidRef )( 
            ISAPrfcBind * This,
            unsigned long lCookie);
        
        END_INTERFACE
    } ISAPrfcBindVtbl;

    interface ISAPrfcBind
    {
        CONST_VTBL struct ISAPrfcBindVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcBind_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcBind_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcBind_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcBind_SetRfcHandle(This,handle)	\
    (This)->lpVtbl -> SetRfcHandle(This,handle)

#define ISAPrfcBind_GetSurrogateProcessId(This,pProcessId)	\
    (This)->lpVtbl -> GetSurrogateProcessId(This,pProcessId)

#define ISAPrfcBind_SetRfcContext(This,pRfcContext)	\
    (This)->lpVtbl -> SetRfcContext(This,pRfcContext)

#define ISAPrfcBind_ReleaseRfcContext(This)	\
    (This)->lpVtbl -> ReleaseRfcContext(This)

#define ISAPrfcBind_SetRfcSession(This,pSession,lCookie)	\
    (This)->lpVtbl -> SetRfcSession(This,pSession,lCookie)

#define ISAPrfcBind_GetRfcContext(This,ppRfcContext)	\
    (This)->lpVtbl -> GetRfcContext(This,ppRfcContext)

#define ISAPrfcBind_SetComplete(This)	\
    (This)->lpVtbl -> SetComplete(This)

#define ISAPrfcBind_SetAbort(This)	\
    (This)->lpVtbl -> SetAbort(This)

#define ISAPrfcBind_EnableCommit(This)	\
    (This)->lpVtbl -> EnableCommit(This)

#define ISAPrfcBind_ClearInvalidRef(This,lCookie)	\
    (This)->lpVtbl -> ClearInvalidRef(This,lCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISAPrfcBind_SetRfcHandle_Proxy( 
    ISAPrfcBind * This,
    unsigned long handle);


void __RPC_STUB ISAPrfcBind_SetRfcHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_GetSurrogateProcessId_Proxy( 
    ISAPrfcBind * This,
    /* [out] */ unsigned long *pProcessId);


void __RPC_STUB ISAPrfcBind_GetSurrogateProcessId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_SetRfcContext_Proxy( 
    ISAPrfcBind * This,
    IUnknown *pRfcContext);


void __RPC_STUB ISAPrfcBind_SetRfcContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_ReleaseRfcContext_Proxy( 
    ISAPrfcBind * This);


void __RPC_STUB ISAPrfcBind_ReleaseRfcContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_SetRfcSession_Proxy( 
    ISAPrfcBind * This,
    IUnknown *pSession,
    unsigned long lCookie);


void __RPC_STUB ISAPrfcBind_SetRfcSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_GetRfcContext_Proxy( 
    ISAPrfcBind * This,
    /* [out] */ IUnknown **ppRfcContext);


void __RPC_STUB ISAPrfcBind_GetRfcContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_SetComplete_Proxy( 
    ISAPrfcBind * This);


void __RPC_STUB ISAPrfcBind_SetComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_SetAbort_Proxy( 
    ISAPrfcBind * This);


void __RPC_STUB ISAPrfcBind_SetAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_EnableCommit_Proxy( 
    ISAPrfcBind * This);


void __RPC_STUB ISAPrfcBind_EnableCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISAPrfcBind_ClearInvalidRef_Proxy( 
    ISAPrfcBind * This,
    unsigned long lCookie);


void __RPC_STUB ISAPrfcBind_ClearInvalidRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcBind_INTERFACE_DEFINED__ */


#ifndef __IRfcProxy_INTERFACE_DEFINED__
#define __IRfcProxy_INTERFACE_DEFINED__

/* interface IRfcProxy */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRfcProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F034842-F427-11D0-90B3-B0D57C000000")
    IRfcProxy : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRfcProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRfcProxy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRfcProxy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRfcProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRfcProxy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRfcProxy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRfcProxy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRfcProxy * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IRfcProxyVtbl;

    interface IRfcProxy
    {
        CONST_VTBL struct IRfcProxyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRfcProxy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRfcProxy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRfcProxy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRfcProxy_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRfcProxy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRfcProxy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRfcProxy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRfcProxy_INTERFACE_DEFINED__ */


#ifndef __IRfcAccessStub_INTERFACE_DEFINED__
#define __IRfcAccessStub_INTERFACE_DEFINED__

/* interface IRfcAccessStub */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_IRfcAccessStub;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F034841-F427-11D0-90B3-B0D57C000000")
    IRfcAccessStub : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitializeGeneric( 
            /* [in] */ IID *pIID,
            /* [in] */ UINT hrfc,
            /* [out] */ void **stub) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRfcAccessStubVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRfcAccessStub * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRfcAccessStub * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRfcAccessStub * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeGeneric )( 
            IRfcAccessStub * This,
            /* [in] */ IID *pIID,
            /* [in] */ UINT hrfc,
            /* [out] */ void **stub);
        
        END_INTERFACE
    } IRfcAccessStubVtbl;

    interface IRfcAccessStub
    {
        CONST_VTBL struct IRfcAccessStubVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRfcAccessStub_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRfcAccessStub_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRfcAccessStub_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRfcAccessStub_InitializeGeneric(This,pIID,hrfc,stub)	\
    (This)->lpVtbl -> InitializeGeneric(This,pIID,hrfc,stub)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRfcAccessStub_InitializeGeneric_Proxy( 
    IRfcAccessStub * This,
    /* [in] */ IID *pIID,
    /* [in] */ UINT hrfc,
    /* [out] */ void **stub);


void __RPC_STUB IRfcAccessStub_InitializeGeneric_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRfcAccessStub_INTERFACE_DEFINED__ */


#ifndef __ICCMonitor_INTERFACE_DEFINED__
#define __ICCMonitor_INTERFACE_DEFINED__

/* interface ICCMonitor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICCMonitor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("354d2fe0-78b3-11d2-bd0b-080009ebbc58")
    ICCMonitor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnections( 
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProcesses( 
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersionInfo( 
            /* [retval][out] */ IDispatch **ppTab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorLog( 
            /* [retval][out] */ BSTR *pLog) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetErrorLog( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICCMonitorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICCMonitor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICCMonitor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICCMonitor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICCMonitor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICCMonitor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICCMonitor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICCMonitor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnections )( 
            ICCMonitor * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProcesses )( 
            ICCMonitor * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersionInfo )( 
            ICCMonitor * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorLog )( 
            ICCMonitor * This,
            /* [retval][out] */ BSTR *pLog);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetErrorLog )( 
            ICCMonitor * This);
        
        END_INTERFACE
    } ICCMonitorVtbl;

    interface ICCMonitor
    {
        CONST_VTBL struct ICCMonitorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICCMonitor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICCMonitor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICCMonitor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICCMonitor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICCMonitor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICCMonitor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICCMonitor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICCMonitor_GetConnections(This,ppTab)	\
    (This)->lpVtbl -> GetConnections(This,ppTab)

#define ICCMonitor_GetProcesses(This,ppTab)	\
    (This)->lpVtbl -> GetProcesses(This,ppTab)

#define ICCMonitor_GetVersionInfo(This,ppTab)	\
    (This)->lpVtbl -> GetVersionInfo(This,ppTab)

#define ICCMonitor_GetErrorLog(This,pLog)	\
    (This)->lpVtbl -> GetErrorLog(This,pLog)

#define ICCMonitor_ResetErrorLog(This)	\
    (This)->lpVtbl -> ResetErrorLog(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICCMonitor_GetConnections_Proxy( 
    ICCMonitor * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ICCMonitor_GetConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICCMonitor_GetProcesses_Proxy( 
    ICCMonitor * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ICCMonitor_GetProcesses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICCMonitor_GetVersionInfo_Proxy( 
    ICCMonitor * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ICCMonitor_GetVersionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICCMonitor_GetErrorLog_Proxy( 
    ICCMonitor * This,
    /* [retval][out] */ BSTR *pLog);


void __RPC_STUB ICCMonitor_GetErrorLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICCMonitor_ResetErrorLog_Proxy( 
    ICCMonitor * This);


void __RPC_STUB ICCMonitor_ResetErrorLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICCMonitor_INTERFACE_DEFINED__ */


#ifndef __IRfcHelper1_INTERFACE_DEFINED__
#define __IRfcHelper1_INTERFACE_DEFINED__

/* interface IRfcHelper1 */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_IRfcHelper1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7be0f72c-e620-11d1-889f-080009e82b31")
    IRfcHelper1 : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRfcHelper1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRfcHelper1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRfcHelper1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRfcHelper1 * This);
        
        END_INTERFACE
    } IRfcHelper1Vtbl;

    interface IRfcHelper1
    {
        CONST_VTBL struct IRfcHelper1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRfcHelper1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRfcHelper1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRfcHelper1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRfcHelper1_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapirfc_0143 */
/* [local] */ 

/*-------------------------------------------------------------------------
 *
 *  SAP AG
 *  Systeme, Anwendungen und Produkte in der Datenverarbeitung
 *  (C) Copyright SAP AG 1998.
 *
 *------------------------------------------------------------------------*/
typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_sapirfc_0143_0001
    {	RfcContext_Initial	= 0,
	RfcContext_Connected	= RfcContext_Initial + 1,
	RfcContext_Cleaned	= RfcContext_Connected + 1,
	RfcContext_Closed	= RfcContext_Cleaned + 1,
	RfcContext_Broken	= RfcContext_Closed + 1,
	RfcContext_Cloned	= RfcContext_Broken + 1,
	RfcContext_WaitingForReset	= RfcContext_Cloned + 1,
	RfcContext_Released	= 0xdead
    } 	RfcContextState;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_sapirfc_0143_0002
    {
    long _size;
    RFCTYPE rfctype;
    long bytes;
    long decimals;
    } 	RfcInvokeScalarType;




extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0143_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapirfc_0143_v0_0_s_ifspec;

#ifndef __ISAPrfcContextRD_INTERFACE_DEFINED__
#define __ISAPrfcContextRD_INTERFACE_DEFINED__

/* interface ISAPrfcContextRD */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcContextRD;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90a60e80-5079-11d1-bca6-080009ebbc58")
    ISAPrfcContextRD : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnRateResource( 
            /* [out] */ RfcContextState *pState,
            /* [out] */ BSTR *ppDestination,
            /* [out] */ DWORD_PTR *pResTypId,
            /* [out] */ void **pTransId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnResetResource( 
            int asyncCleanUp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActivateFromPool( 
            BSTR destination,
            void *transId,
            ISAPrfcContextSource *pContextSource,
            IUnknown *pIUnknown_ADOConn) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnDestroyResource( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcContextRDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcContextRD * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcContextRD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcContextRD * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnRateResource )( 
            ISAPrfcContextRD * This,
            /* [out] */ RfcContextState *pState,
            /* [out] */ BSTR *ppDestination,
            /* [out] */ DWORD_PTR *pResTypId,
            /* [out] */ void **pTransId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnResetResource )( 
            ISAPrfcContextRD * This,
            int asyncCleanUp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActivateFromPool )( 
            ISAPrfcContextRD * This,
            BSTR destination,
            void *transId,
            ISAPrfcContextSource *pContextSource,
            IUnknown *pIUnknown_ADOConn);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnDestroyResource )( 
            ISAPrfcContextRD * This);
        
        END_INTERFACE
    } ISAPrfcContextRDVtbl;

    interface ISAPrfcContextRD
    {
        CONST_VTBL struct ISAPrfcContextRDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcContextRD_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcContextRD_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcContextRD_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcContextRD_OnRateResource(This,pState,ppDestination,pResTypId,pTransId)	\
    (This)->lpVtbl -> OnRateResource(This,pState,ppDestination,pResTypId,pTransId)

#define ISAPrfcContextRD_OnResetResource(This,asyncCleanUp)	\
    (This)->lpVtbl -> OnResetResource(This,asyncCleanUp)

#define ISAPrfcContextRD_ActivateFromPool(This,destination,transId,pContextSource,pIUnknown_ADOConn)	\
    (This)->lpVtbl -> ActivateFromPool(This,destination,transId,pContextSource,pIUnknown_ADOConn)

#define ISAPrfcContextRD_OnDestroyResource(This)	\
    (This)->lpVtbl -> OnDestroyResource(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextRD_OnRateResource_Proxy( 
    ISAPrfcContextRD * This,
    /* [out] */ RfcContextState *pState,
    /* [out] */ BSTR *ppDestination,
    /* [out] */ DWORD_PTR *pResTypId,
    /* [out] */ void **pTransId);


void __RPC_STUB ISAPrfcContextRD_OnRateResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextRD_OnResetResource_Proxy( 
    ISAPrfcContextRD * This,
    int asyncCleanUp);


void __RPC_STUB ISAPrfcContextRD_OnResetResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextRD_ActivateFromPool_Proxy( 
    ISAPrfcContextRD * This,
    BSTR destination,
    void *transId,
    ISAPrfcContextSource *pContextSource,
    IUnknown *pIUnknown_ADOConn);


void __RPC_STUB ISAPrfcContextRD_ActivateFromPool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextRD_OnDestroyResource_Proxy( 
    ISAPrfcContextRD * This);


void __RPC_STUB ISAPrfcContextRD_OnDestroyResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcContextRD_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcContext_INTERFACE_DEFINED__
#define __ISAPrfcContext_INTERFACE_DEFINED__

/* interface ISAPrfcContext */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bd8dc610-5079-11d1-bca6-080009ebbc58")
    ISAPrfcContext : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLastError( 
            /* [out] */ LONG *errorcode,
            /* [out] */ VARIANT *errormessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRFC_HANDLE( 
            /* [out] */ RFC_HANDLE *phRfc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRFC_HANDLE( 
            /* [in] */ RFC_HANDLE hRfc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FreeResource( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PublishLastError( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeStartFunction( 
            /* [in] */ wchar_t *name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeSimpleParameterByName( 
            /* [in] */ RFCPARAM parmType,
            /* [in] */ wchar_t *name,
            /* [in] */ RfcInvokeScalarType *pType,
            /* [in] */ VARTYPE vartype,
            /* [out][in] */ VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeExecute( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAbort( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetComplete( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeTableByName( 
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeStructureByName( 
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AdviseRfcGuiSink( 
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableCommit( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetConnectionAttribute( 
            /* [in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLastError )( 
            ISAPrfcContext * This,
            /* [out] */ LONG *errorcode,
            /* [out] */ VARIANT *errormessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRFC_HANDLE )( 
            ISAPrfcContext * This,
            /* [out] */ RFC_HANDLE *phRfc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRFC_HANDLE )( 
            ISAPrfcContext * This,
            /* [in] */ RFC_HANDLE hRfc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FreeResource )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PublishLastError )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeStartFunction )( 
            ISAPrfcContext * This,
            /* [in] */ wchar_t *name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeSimpleParameterByName )( 
            ISAPrfcContext * This,
            /* [in] */ RFCPARAM parmType,
            /* [in] */ wchar_t *name,
            /* [in] */ RfcInvokeScalarType *pType,
            /* [in] */ VARTYPE vartype,
            /* [out][in] */ VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeExecute )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAbort )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetComplete )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeTableByName )( 
            ISAPrfcContext * This,
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeStructureByName )( 
            ISAPrfcContext * This,
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseRfcGuiSink )( 
            ISAPrfcContext * This,
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableCommit )( 
            ISAPrfcContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPrfcContext * This,
            /* [in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        END_INTERFACE
    } ISAPrfcContextVtbl;

    interface ISAPrfcContext
    {
        CONST_VTBL struct ISAPrfcContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcContext_GetLastError(This,errorcode,errormessage)	\
    (This)->lpVtbl -> GetLastError(This,errorcode,errormessage)

#define ISAPrfcContext_GetRFC_HANDLE(This,phRfc)	\
    (This)->lpVtbl -> GetRFC_HANDLE(This,phRfc)

#define ISAPrfcContext_SetRFC_HANDLE(This,hRfc)	\
    (This)->lpVtbl -> SetRFC_HANDLE(This,hRfc)

#define ISAPrfcContext_FreeResource(This)	\
    (This)->lpVtbl -> FreeResource(This)

#define ISAPrfcContext_PublishLastError(This)	\
    (This)->lpVtbl -> PublishLastError(This)

#define ISAPrfcContext_AbapInvokeStartFunction(This,name)	\
    (This)->lpVtbl -> AbapInvokeStartFunction(This,name)

#define ISAPrfcContext_AbapInvokeSimpleParameterByName(This,parmType,name,pType,vartype,pVariant)	\
    (This)->lpVtbl -> AbapInvokeSimpleParameterByName(This,parmType,name,pType,vartype,pVariant)

#define ISAPrfcContext_AbapInvokeExecute(This)	\
    (This)->lpVtbl -> AbapInvokeExecute(This)

#define ISAPrfcContext_SetAbort(This)	\
    (This)->lpVtbl -> SetAbort(This)

#define ISAPrfcContext_SetComplete(This)	\
    (This)->lpVtbl -> SetComplete(This)

#define ISAPrfcContext_AbapInvokeTableByName(This,param,name,pISAPrfcStructDesc,pVariant)	\
    (This)->lpVtbl -> AbapInvokeTableByName(This,param,name,pISAPrfcStructDesc,pVariant)

#define ISAPrfcContext_AbapInvokeStructureByName(This,param,name,pISAPrfcStructDesc,pVariant)	\
    (This)->lpVtbl -> AbapInvokeStructureByName(This,param,name,pISAPrfcStructDesc,pVariant)

#define ISAPrfcContext_AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)	\
    (This)->lpVtbl -> AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)

#define ISAPrfcContext_EnableCommit(This)	\
    (This)->lpVtbl -> EnableCommit(This)

#define ISAPrfcContext_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_GetLastError_Proxy( 
    ISAPrfcContext * This,
    /* [out] */ LONG *errorcode,
    /* [out] */ VARIANT *errormessage);


void __RPC_STUB ISAPrfcContext_GetLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_GetRFC_HANDLE_Proxy( 
    ISAPrfcContext * This,
    /* [out] */ RFC_HANDLE *phRfc);


void __RPC_STUB ISAPrfcContext_GetRFC_HANDLE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_SetRFC_HANDLE_Proxy( 
    ISAPrfcContext * This,
    /* [in] */ RFC_HANDLE hRfc);


void __RPC_STUB ISAPrfcContext_SetRFC_HANDLE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_FreeResource_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_FreeResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_PublishLastError_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_PublishLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AbapInvokeStartFunction_Proxy( 
    ISAPrfcContext * This,
    /* [in] */ wchar_t *name);


void __RPC_STUB ISAPrfcContext_AbapInvokeStartFunction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AbapInvokeSimpleParameterByName_Proxy( 
    ISAPrfcContext * This,
    /* [in] */ RFCPARAM parmType,
    /* [in] */ wchar_t *name,
    /* [in] */ RfcInvokeScalarType *pType,
    /* [in] */ VARTYPE vartype,
    /* [out][in] */ VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext_AbapInvokeSimpleParameterByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AbapInvokeExecute_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_AbapInvokeExecute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_SetAbort_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_SetAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_SetComplete_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_SetComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AbapInvokeTableByName_Proxy( 
    ISAPrfcContext * This,
    RFCPARAM param,
    wchar_t *name,
    ISAPrfcStructDesc *pISAPrfcStructDesc,
    VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext_AbapInvokeTableByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AbapInvokeStructureByName_Proxy( 
    ISAPrfcContext * This,
    RFCPARAM param,
    wchar_t *name,
    ISAPrfcStructDesc *pISAPrfcStructDesc,
    VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext_AbapInvokeStructureByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_AdviseRfcGuiSink_Proxy( 
    ISAPrfcContext * This,
    /* [in] */ IDispatch *pIRfcGuiSink,
    /* [in] */ short AbapDebug,
    /* [in] */ short UseSapGui);


void __RPC_STUB ISAPrfcContext_AdviseRfcGuiSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_EnableCommit_Proxy( 
    ISAPrfcContext * This);


void __RPC_STUB ISAPrfcContext_EnableCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext_GetConnectionAttribute_Proxy( 
    ISAPrfcContext * This,
    /* [in] */ BSTR AttrName,
    /* [retval][out] */ VARIANT *pAttrValue);


void __RPC_STUB ISAPrfcContext_GetConnectionAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcContext_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcContext2_INTERFACE_DEFINED__
#define __ISAPrfcContext2_INTERFACE_DEFINED__

/* interface ISAPrfcContext2 */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcContext2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94BD4CAF-38A7-491e-A145-44773FB26936")
    ISAPrfcContext2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLastError( 
            /* [out] */ LONG *errorcode,
            /* [out] */ VARIANT *errormessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRFC_HANDLE( 
            /* [out] */ RFC_HANDLE *phRfc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRFC_HANDLE( 
            /* [in] */ RFC_HANDLE hRfc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FreeResource( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PublishLastError( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeStartTFunction( 
            /* [in] */ wchar_t *name,
            /* [in] */ int uRfcType,
            /* [in] */ wchar_t *TID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeStartQFunction( 
            /* [in] */ wchar_t *name,
            /* [in] */ int uRfcType,
            /* [in] */ wchar_t *TID,
            /* [in] */ wchar_t *QName,
            /* [in] */ unsigned long QCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeSimpleParameterByName( 
            /* [in] */ RFCPARAM parmType,
            /* [in] */ wchar_t *name,
            /* [in] */ RfcInvokeScalarType *pType,
            /* [in] */ VARTYPE vartype,
            /* [out][in] */ VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeExecute( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAbort( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetComplete( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeTableByName( 
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbapInvokeStructureByName( 
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AdviseRfcGuiSink( 
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableCommit( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetConnectionAttribute( 
            /* [in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConfirmTID( 
            /* [in] */ wchar_t *TID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcContext2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcContext2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcContext2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLastError )( 
            ISAPrfcContext2 * This,
            /* [out] */ LONG *errorcode,
            /* [out] */ VARIANT *errormessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRFC_HANDLE )( 
            ISAPrfcContext2 * This,
            /* [out] */ RFC_HANDLE *phRfc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRFC_HANDLE )( 
            ISAPrfcContext2 * This,
            /* [in] */ RFC_HANDLE hRfc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FreeResource )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PublishLastError )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeStartTFunction )( 
            ISAPrfcContext2 * This,
            /* [in] */ wchar_t *name,
            /* [in] */ int uRfcType,
            /* [in] */ wchar_t *TID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeStartQFunction )( 
            ISAPrfcContext2 * This,
            /* [in] */ wchar_t *name,
            /* [in] */ int uRfcType,
            /* [in] */ wchar_t *TID,
            /* [in] */ wchar_t *QName,
            /* [in] */ unsigned long QCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeSimpleParameterByName )( 
            ISAPrfcContext2 * This,
            /* [in] */ RFCPARAM parmType,
            /* [in] */ wchar_t *name,
            /* [in] */ RfcInvokeScalarType *pType,
            /* [in] */ VARTYPE vartype,
            /* [out][in] */ VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeExecute )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAbort )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetComplete )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeTableByName )( 
            ISAPrfcContext2 * This,
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbapInvokeStructureByName )( 
            ISAPrfcContext2 * This,
            RFCPARAM param,
            wchar_t *name,
            ISAPrfcStructDesc *pISAPrfcStructDesc,
            VARIANT *pVariant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseRfcGuiSink )( 
            ISAPrfcContext2 * This,
            /* [in] */ IDispatch *pIRfcGuiSink,
            /* [in] */ short AbapDebug,
            /* [in] */ short UseSapGui);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableCommit )( 
            ISAPrfcContext2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionAttribute )( 
            ISAPrfcContext2 * This,
            /* [in] */ BSTR AttrName,
            /* [retval][out] */ VARIANT *pAttrValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConfirmTID )( 
            ISAPrfcContext2 * This,
            /* [in] */ wchar_t *TID);
        
        END_INTERFACE
    } ISAPrfcContext2Vtbl;

    interface ISAPrfcContext2
    {
        CONST_VTBL struct ISAPrfcContext2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcContext2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcContext2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcContext2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcContext2_GetLastError(This,errorcode,errormessage)	\
    (This)->lpVtbl -> GetLastError(This,errorcode,errormessage)

#define ISAPrfcContext2_GetRFC_HANDLE(This,phRfc)	\
    (This)->lpVtbl -> GetRFC_HANDLE(This,phRfc)

#define ISAPrfcContext2_SetRFC_HANDLE(This,hRfc)	\
    (This)->lpVtbl -> SetRFC_HANDLE(This,hRfc)

#define ISAPrfcContext2_FreeResource(This)	\
    (This)->lpVtbl -> FreeResource(This)

#define ISAPrfcContext2_PublishLastError(This)	\
    (This)->lpVtbl -> PublishLastError(This)

#define ISAPrfcContext2_AbapInvokeStartTFunction(This,name,uRfcType,TID)	\
    (This)->lpVtbl -> AbapInvokeStartTFunction(This,name,uRfcType,TID)

#define ISAPrfcContext2_AbapInvokeStartQFunction(This,name,uRfcType,TID,QName,QCount)	\
    (This)->lpVtbl -> AbapInvokeStartQFunction(This,name,uRfcType,TID,QName,QCount)

#define ISAPrfcContext2_AbapInvokeSimpleParameterByName(This,parmType,name,pType,vartype,pVariant)	\
    (This)->lpVtbl -> AbapInvokeSimpleParameterByName(This,parmType,name,pType,vartype,pVariant)

#define ISAPrfcContext2_AbapInvokeExecute(This)	\
    (This)->lpVtbl -> AbapInvokeExecute(This)

#define ISAPrfcContext2_SetAbort(This)	\
    (This)->lpVtbl -> SetAbort(This)

#define ISAPrfcContext2_SetComplete(This)	\
    (This)->lpVtbl -> SetComplete(This)

#define ISAPrfcContext2_AbapInvokeTableByName(This,param,name,pISAPrfcStructDesc,pVariant)	\
    (This)->lpVtbl -> AbapInvokeTableByName(This,param,name,pISAPrfcStructDesc,pVariant)

#define ISAPrfcContext2_AbapInvokeStructureByName(This,param,name,pISAPrfcStructDesc,pVariant)	\
    (This)->lpVtbl -> AbapInvokeStructureByName(This,param,name,pISAPrfcStructDesc,pVariant)

#define ISAPrfcContext2_AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)	\
    (This)->lpVtbl -> AdviseRfcGuiSink(This,pIRfcGuiSink,AbapDebug,UseSapGui)

#define ISAPrfcContext2_EnableCommit(This)	\
    (This)->lpVtbl -> EnableCommit(This)

#define ISAPrfcContext2_GetConnectionAttribute(This,AttrName,pAttrValue)	\
    (This)->lpVtbl -> GetConnectionAttribute(This,AttrName,pAttrValue)

#define ISAPrfcContext2_ConfirmTID(This,TID)	\
    (This)->lpVtbl -> ConfirmTID(This,TID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_GetLastError_Proxy( 
    ISAPrfcContext2 * This,
    /* [out] */ LONG *errorcode,
    /* [out] */ VARIANT *errormessage);


void __RPC_STUB ISAPrfcContext2_GetLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_GetRFC_HANDLE_Proxy( 
    ISAPrfcContext2 * This,
    /* [out] */ RFC_HANDLE *phRfc);


void __RPC_STUB ISAPrfcContext2_GetRFC_HANDLE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_SetRFC_HANDLE_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ RFC_HANDLE hRfc);


void __RPC_STUB ISAPrfcContext2_SetRFC_HANDLE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_FreeResource_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_FreeResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_PublishLastError_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_PublishLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeStartTFunction_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ wchar_t *name,
    /* [in] */ int uRfcType,
    /* [in] */ wchar_t *TID);


void __RPC_STUB ISAPrfcContext2_AbapInvokeStartTFunction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeStartQFunction_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ wchar_t *name,
    /* [in] */ int uRfcType,
    /* [in] */ wchar_t *TID,
    /* [in] */ wchar_t *QName,
    /* [in] */ unsigned long QCount);


void __RPC_STUB ISAPrfcContext2_AbapInvokeStartQFunction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeSimpleParameterByName_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ RFCPARAM parmType,
    /* [in] */ wchar_t *name,
    /* [in] */ RfcInvokeScalarType *pType,
    /* [in] */ VARTYPE vartype,
    /* [out][in] */ VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext2_AbapInvokeSimpleParameterByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeExecute_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_AbapInvokeExecute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_SetAbort_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_SetAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_SetComplete_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_SetComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeTableByName_Proxy( 
    ISAPrfcContext2 * This,
    RFCPARAM param,
    wchar_t *name,
    ISAPrfcStructDesc *pISAPrfcStructDesc,
    VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext2_AbapInvokeTableByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AbapInvokeStructureByName_Proxy( 
    ISAPrfcContext2 * This,
    RFCPARAM param,
    wchar_t *name,
    ISAPrfcStructDesc *pISAPrfcStructDesc,
    VARIANT *pVariant);


void __RPC_STUB ISAPrfcContext2_AbapInvokeStructureByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_AdviseRfcGuiSink_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ IDispatch *pIRfcGuiSink,
    /* [in] */ short AbapDebug,
    /* [in] */ short UseSapGui);


void __RPC_STUB ISAPrfcContext2_AdviseRfcGuiSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_EnableCommit_Proxy( 
    ISAPrfcContext2 * This);


void __RPC_STUB ISAPrfcContext2_EnableCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_GetConnectionAttribute_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ BSTR AttrName,
    /* [retval][out] */ VARIANT *pAttrValue);


void __RPC_STUB ISAPrfcContext2_GetConnectionAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContext2_ConfirmTID_Proxy( 
    ISAPrfcContext2 * This,
    /* [in] */ wchar_t *TID);


void __RPC_STUB ISAPrfcContext2_ConfirmTID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcContext2_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcContextSource_INTERFACE_DEFINED__
#define __ISAPrfcContextSource_INTERFACE_DEFINED__

/* interface ISAPrfcContextSource */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcContextSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB8B5770-2537-11d1-BC9D-080009EBBC58")
    ISAPrfcContextSource : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR destination,
            /* [in] */ BSTR userid,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR language,
            /* [in] */ BSTR client,
            /* [in] */ IUnknown *pUnk,
            /* [out] */ ISAPrfcContext **ppISAPrfcContext,
            /* [in] */ const IID *pIID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Return( 
            /* [in] */ ISAPrfcContext *pISAPrfcContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcContextSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcContextSource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcContextSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcContextSource * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            ISAPrfcContextSource * This,
            /* [in] */ BSTR destination,
            /* [in] */ BSTR userid,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR language,
            /* [in] */ BSTR client,
            /* [in] */ IUnknown *pUnk,
            /* [out] */ ISAPrfcContext **ppISAPrfcContext,
            /* [in] */ const IID *pIID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Return )( 
            ISAPrfcContextSource * This,
            /* [in] */ ISAPrfcContext *pISAPrfcContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISAPrfcContextSource * This);
        
        END_INTERFACE
    } ISAPrfcContextSourceVtbl;

    interface ISAPrfcContextSource
    {
        CONST_VTBL struct ISAPrfcContextSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcContextSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcContextSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcContextSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcContextSource_Get(This,destination,userid,passwd,language,client,pUnk,ppISAPrfcContext,pIID)	\
    (This)->lpVtbl -> Get(This,destination,userid,passwd,language,client,pUnk,ppISAPrfcContext,pIID)

#define ISAPrfcContextSource_Return(This,pISAPrfcContext)	\
    (This)->lpVtbl -> Return(This,pISAPrfcContext)

#define ISAPrfcContextSource_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource_Get_Proxy( 
    ISAPrfcContextSource * This,
    /* [in] */ BSTR destination,
    /* [in] */ BSTR userid,
    /* [in] */ BSTR passwd,
    /* [in] */ BSTR language,
    /* [in] */ BSTR client,
    /* [in] */ IUnknown *pUnk,
    /* [out] */ ISAPrfcContext **ppISAPrfcContext,
    /* [in] */ const IID *pIID);


void __RPC_STUB ISAPrfcContextSource_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource_Return_Proxy( 
    ISAPrfcContextSource * This,
    /* [in] */ ISAPrfcContext *pISAPrfcContext);


void __RPC_STUB ISAPrfcContextSource_Return_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource_Close_Proxy( 
    ISAPrfcContextSource * This);


void __RPC_STUB ISAPrfcContextSource_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcContextSource_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcContextSource2_INTERFACE_DEFINED__
#define __ISAPrfcContextSource2_INTERFACE_DEFINED__

/* interface ISAPrfcContextSource2 */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPrfcContextSource2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24729B1B-84C7-4f03-8538-57F68B04B284")
    ISAPrfcContextSource2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR destination,
            /* [in] */ BSTR userid,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR language,
            /* [in] */ BSTR client,
            /* [in] */ IUnknown *pUnk,
            /* [out] */ ISAPrfcContext **ppISAPrfcContext,
            /* [in] */ const IID *pIID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Return( 
            /* [in] */ ISAPrfcContext *pISAPrfcContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTID( 
            /* [in] */ wchar_t *TID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcContextSource2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcContextSource2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcContextSource2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcContextSource2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            ISAPrfcContextSource2 * This,
            /* [in] */ BSTR destination,
            /* [in] */ BSTR userid,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR language,
            /* [in] */ BSTR client,
            /* [in] */ IUnknown *pUnk,
            /* [out] */ ISAPrfcContext **ppISAPrfcContext,
            /* [in] */ const IID *pIID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Return )( 
            ISAPrfcContextSource2 * This,
            /* [in] */ ISAPrfcContext *pISAPrfcContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISAPrfcContextSource2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTID )( 
            ISAPrfcContextSource2 * This,
            /* [in] */ wchar_t *TID);
        
        END_INTERFACE
    } ISAPrfcContextSource2Vtbl;

    interface ISAPrfcContextSource2
    {
        CONST_VTBL struct ISAPrfcContextSource2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcContextSource2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcContextSource2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcContextSource2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcContextSource2_Get(This,destination,userid,passwd,language,client,pUnk,ppISAPrfcContext,pIID)	\
    (This)->lpVtbl -> Get(This,destination,userid,passwd,language,client,pUnk,ppISAPrfcContext,pIID)

#define ISAPrfcContextSource2_Return(This,pISAPrfcContext)	\
    (This)->lpVtbl -> Return(This,pISAPrfcContext)

#define ISAPrfcContextSource2_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define ISAPrfcContextSource2_CreateTID(This,TID)	\
    (This)->lpVtbl -> CreateTID(This,TID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource2_Get_Proxy( 
    ISAPrfcContextSource2 * This,
    /* [in] */ BSTR destination,
    /* [in] */ BSTR userid,
    /* [in] */ BSTR passwd,
    /* [in] */ BSTR language,
    /* [in] */ BSTR client,
    /* [in] */ IUnknown *pUnk,
    /* [out] */ ISAPrfcContext **ppISAPrfcContext,
    /* [in] */ const IID *pIID);


void __RPC_STUB ISAPrfcContextSource2_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource2_Return_Proxy( 
    ISAPrfcContextSource2 * This,
    /* [in] */ ISAPrfcContext *pISAPrfcContext);


void __RPC_STUB ISAPrfcContextSource2_Return_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource2_Close_Proxy( 
    ISAPrfcContextSource2 * This);


void __RPC_STUB ISAPrfcContextSource2_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcContextSource2_CreateTID_Proxy( 
    ISAPrfcContextSource2 * This,
    /* [in] */ wchar_t *TID);


void __RPC_STUB ISAPrfcContextSource2_CreateTID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcContextSource2_INTERFACE_DEFINED__ */


#ifndef __ISAPTxStart_INTERFACE_DEFINED__
#define __ISAPTxStart_INTERFACE_DEFINED__

/* interface ISAPTxStart */
/* [object][unique][helpstring][local][uuid] */ 


EXTERN_C const IID IID_ISAPTxStart;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("292228e0-5079-11d1-bca6-080009ebbc58")
    ISAPTxStart : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE TxStart( 
            /* [in] */ RFC_HANDLE hrfc,
            /* [in] */ BSTR destination) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPTxStartVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPTxStart * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPTxStart * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPTxStart * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *TxStart )( 
            ISAPTxStart * This,
            /* [in] */ RFC_HANDLE hrfc,
            /* [in] */ BSTR destination);
        
        END_INTERFACE
    } ISAPTxStartVtbl;

    interface ISAPTxStart
    {
        CONST_VTBL struct ISAPTxStartVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPTxStart_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPTxStart_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPTxStart_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPTxStart_TxStart(This,hrfc,destination)	\
    (This)->lpVtbl -> TxStart(This,hrfc,destination)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPTxStart_TxStart_Proxy( 
    ISAPTxStart * This,
    /* [in] */ RFC_HANDLE hrfc,
    /* [in] */ BSTR destination);


void __RPC_STUB ISAPTxStart_TxStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPTxStart_INTERFACE_DEFINED__ */


#ifndef __ISAPrfcTraceU_INTERFACE_DEFINED__
#define __ISAPrfcTraceU_INTERFACE_DEFINED__

/* interface ISAPrfcTraceU */
/* [object][unique][helpstring][local][uuid] */ 


EXTERN_C const IID IID_ISAPrfcTraceU;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5955C2F8-0013-11d4-B6D1-00609419505A")
    ISAPrfcTraceU : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnError( 
            /* [in] */ OLECHAR *entryPoint,
            /* [in] */ OLECHAR *fname,
            /* [in] */ int line,
            /* [in] */ OLECHAR *text,
            /* [in] */ HRESULT hr) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Trace( 
            /* [in] */ OLECHAR *entryPoint,
            /* [in] */ OLECHAR *fname,
            /* [in] */ int line,
            /* [in] */ OLECHAR *text) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISAPrfcTraceUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPrfcTraceU * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPrfcTraceU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPrfcTraceU * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnError )( 
            ISAPrfcTraceU * This,
            /* [in] */ OLECHAR *entryPoint,
            /* [in] */ OLECHAR *fname,
            /* [in] */ int line,
            /* [in] */ OLECHAR *text,
            /* [in] */ HRESULT hr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Trace )( 
            ISAPrfcTraceU * This,
            /* [in] */ OLECHAR *entryPoint,
            /* [in] */ OLECHAR *fname,
            /* [in] */ int line,
            /* [in] */ OLECHAR *text);
        
        END_INTERFACE
    } ISAPrfcTraceUVtbl;

    interface ISAPrfcTraceU
    {
        CONST_VTBL struct ISAPrfcTraceUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPrfcTraceU_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPrfcTraceU_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPrfcTraceU_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPrfcTraceU_OnError(This,entryPoint,fname,line,text,hr)	\
    (This)->lpVtbl -> OnError(This,entryPoint,fname,line,text,hr)

#define ISAPrfcTraceU_Trace(This,entryPoint,fname,line,text)	\
    (This)->lpVtbl -> Trace(This,entryPoint,fname,line,text)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcTraceU_OnError_Proxy( 
    ISAPrfcTraceU * This,
    /* [in] */ OLECHAR *entryPoint,
    /* [in] */ OLECHAR *fname,
    /* [in] */ int line,
    /* [in] */ OLECHAR *text,
    /* [in] */ HRESULT hr);


void __RPC_STUB ISAPrfcTraceU_OnError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPrfcTraceU_Trace_Proxy( 
    ISAPrfcTraceU * This,
    /* [in] */ OLECHAR *entryPoint,
    /* [in] */ OLECHAR *fname,
    /* [in] */ int line,
    /* [in] */ OLECHAR *text);


void __RPC_STUB ISAPrfcTraceU_Trace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPrfcTraceU_INTERFACE_DEFINED__ */


#ifndef __IRfcGuiSink_INTERFACE_DEFINED__
#define __IRfcGuiSink_INTERFACE_DEFINED__

/* interface IRfcGuiSink */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRfcGuiSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C0F1282-6027-11D1-B766-00A0C9308BE6")
    IRfcGuiSink : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchGui( 
            /* [in] */ BSTR StartParam,
            /* [out] */ BSTR *ErrMessage,
            /* [out] */ BSTR *ReturnParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRfcGuiSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRfcGuiSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRfcGuiSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRfcGuiSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRfcGuiSink * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRfcGuiSink * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRfcGuiSink * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRfcGuiSink * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LaunchGui )( 
            IRfcGuiSink * This,
            /* [in] */ BSTR StartParam,
            /* [out] */ BSTR *ErrMessage,
            /* [out] */ BSTR *ReturnParam);
        
        END_INTERFACE
    } IRfcGuiSinkVtbl;

    interface IRfcGuiSink
    {
        CONST_VTBL struct IRfcGuiSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRfcGuiSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRfcGuiSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRfcGuiSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRfcGuiSink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRfcGuiSink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRfcGuiSink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRfcGuiSink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRfcGuiSink_LaunchGui(This,StartParam,ErrMessage,ReturnParam)	\
    (This)->lpVtbl -> LaunchGui(This,StartParam,ErrMessage,ReturnParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRfcGuiSink_LaunchGui_Proxy( 
    IRfcGuiSink * This,
    /* [in] */ BSTR StartParam,
    /* [out] */ BSTR *ErrMessage,
    /* [out] */ BSTR *ReturnParam);


void __RPC_STUB IRfcGuiSink_LaunchGui_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRfcGuiSink_INTERFACE_DEFINED__ */


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


#ifndef __ISAPCatalog4CU_INTERFACE_DEFINED__
#define __ISAPCatalog4CU_INTERFACE_DEFINED__

/* interface ISAPCatalog4CU */
/* [unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISAPCatalog4CU;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5955C2F1-0013-11d4-B6D1-00609419505A")
    ISAPCatalog4CU : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateFromData( 
            /* [string][in] */ const OLECHAR *wcsSchemaName,
            /* [in] */ unsigned long lObjLen,
            /* [size_is][in] */ byte *pScObj,
            /* [in] */ unsigned long lVerbLen,
            /* [size_is][in] */ byte *pScVerb) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeType( 
            /* [string][in] */ const OLECHAR *typeName,
            /* [string][in] */ const OLECHAR *typeAbapName,
            /* [string][in] */ const OLECHAR *typeDescription,
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

    typedef struct ISAPCatalog4CUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISAPCatalog4CU * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISAPCatalog4CU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISAPCatalog4CU * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateFromData )( 
            ISAPCatalog4CU * This,
            /* [string][in] */ const OLECHAR *wcsSchemaName,
            /* [in] */ unsigned long lObjLen,
            /* [size_is][in] */ byte *pScObj,
            /* [in] */ unsigned long lVerbLen,
            /* [size_is][in] */ byte *pScVerb);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeType )( 
            ISAPCatalog4CU * This,
            /* [string][in] */ const OLECHAR *typeName,
            /* [string][in] */ const OLECHAR *typeAbapName,
            /* [string][in] */ const OLECHAR *typeDescription,
            /* [in] */ unsigned long lTypeEntryLen,
            /* [in] */ byte *pTypeEntries,
            /* [in] */ unsigned long lEntries);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSchemata )( 
            ISAPCatalog4CU * This,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetClasses )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethods )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTypes )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethodParameters )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR methodName,
            /* [retval][out] */ IDispatch **ppTab);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTypeColumns )( 
            ISAPCatalog4CU * This,
            /* [in] */ BSTR schemaName,
            /* [in] */ BSTR className,
            /* [in] */ BSTR typeName,
            /* [retval][out] */ IDispatch **ppTab);
        
        END_INTERFACE
    } ISAPCatalog4CUVtbl;

    interface ISAPCatalog4CU
    {
        CONST_VTBL struct ISAPCatalog4CUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISAPCatalog4CU_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISAPCatalog4CU_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISAPCatalog4CU_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISAPCatalog4CU_CreateFromData(This,wcsSchemaName,lObjLen,pScObj,lVerbLen,pScVerb)	\
    (This)->lpVtbl -> CreateFromData(This,wcsSchemaName,lObjLen,pScObj,lVerbLen,pScVerb)

#define ISAPCatalog4CU_InitializeType(This,typeName,typeAbapName,typeDescription,lTypeEntryLen,pTypeEntries,lEntries)	\
    (This)->lpVtbl -> InitializeType(This,typeName,typeAbapName,typeDescription,lTypeEntryLen,pTypeEntries,lEntries)

#define ISAPCatalog4CU_GetSchemata(This,ppTab)	\
    (This)->lpVtbl -> GetSchemata(This,ppTab)

#define ISAPCatalog4CU_GetClasses(This,schemaName,ppTab)	\
    (This)->lpVtbl -> GetClasses(This,schemaName,ppTab)

#define ISAPCatalog4CU_GetMethods(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetMethods(This,schemaName,className,ppTab)

#define ISAPCatalog4CU_GetProperties(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetProperties(This,schemaName,className,ppTab)

#define ISAPCatalog4CU_GetTypes(This,schemaName,className,ppTab)	\
    (This)->lpVtbl -> GetTypes(This,schemaName,className,ppTab)

#define ISAPCatalog4CU_GetMethodParameters(This,schemaName,className,methodName,ppTab)	\
    (This)->lpVtbl -> GetMethodParameters(This,schemaName,className,methodName,ppTab)

#define ISAPCatalog4CU_GetTypeColumns(This,schemaName,className,typeName,ppTab)	\
    (This)->lpVtbl -> GetTypeColumns(This,schemaName,className,typeName,ppTab)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_CreateFromData_Proxy( 
    ISAPCatalog4CU * This,
    /* [string][in] */ const OLECHAR *wcsSchemaName,
    /* [in] */ unsigned long lObjLen,
    /* [size_is][in] */ byte *pScObj,
    /* [in] */ unsigned long lVerbLen,
    /* [size_is][in] */ byte *pScVerb);


void __RPC_STUB ISAPCatalog4CU_CreateFromData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_InitializeType_Proxy( 
    ISAPCatalog4CU * This,
    /* [string][in] */ const OLECHAR *typeName,
    /* [string][in] */ const OLECHAR *typeAbapName,
    /* [string][in] */ const OLECHAR *typeDescription,
    /* [in] */ unsigned long lTypeEntryLen,
    /* [in] */ byte *pTypeEntries,
    /* [in] */ unsigned long lEntries);


void __RPC_STUB ISAPCatalog4CU_InitializeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetSchemata_Proxy( 
    ISAPCatalog4CU * This,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetSchemata_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetClasses_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetClasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetMethods_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetProperties_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetTypes_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetMethodParameters_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [in] */ BSTR methodName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetMethodParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISAPCatalog4CU_GetTypeColumns_Proxy( 
    ISAPCatalog4CU * This,
    /* [in] */ BSTR schemaName,
    /* [in] */ BSTR className,
    /* [in] */ BSTR typeName,
    /* [retval][out] */ IDispatch **ppTab);


void __RPC_STUB ISAPCatalog4CU_GetTypeColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISAPCatalog4CU_INTERFACE_DEFINED__ */


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



#ifndef __IRFC32Lib_LIBRARY_DEFINED__
#define __IRFC32Lib_LIBRARY_DEFINED__

/* library IRFC32Lib */
/* [helpstring][version][uuid] */ 




EXTERN_C const IID LIBID_IRFC32Lib;

EXTERN_C const CLSID CLSID_CSAPrfcITab;

#ifdef __cplusplus

class DECLSPEC_UUID("7CC52276-6D59-11D0-ACCA-080009D213D2")
CSAPrfcITab;
#endif

EXTERN_C const CLSID CLSID_CSAPrfcStructDesc;

#ifdef __cplusplus

class DECLSPEC_UUID("3AAC5D6A-7DB1-11D0-ACCF-080009D213D2")
CSAPrfcStructDesc;
#endif

EXTERN_C const CLSID CLSID_CSAPrfcStructView;

#ifdef __cplusplus

class DECLSPEC_UUID("3AAC5D6F-7DB1-11D0-ACCF-080009D213D2")
CSAPrfcStructView;
#endif

EXTERN_C const CLSID CLSID_CSAPrfcDataConvert;

#ifdef __cplusplus

class DECLSPEC_UUID("18D30462-90A9-11d0-ACDB-080009D213D2")
CSAPrfcDataConvert;
#endif

EXTERN_C const CLSID CLSID_RfcProxy;

#ifdef __cplusplus

class DECLSPEC_UUID("8F034843-F427-11D0-90B3-B0D57C000000")
RfcProxy;
#endif

EXTERN_C const CLSID CLSID_RfcContext;

#ifdef __cplusplus

class DECLSPEC_UUID("AE2119A3-0CC4-11D1-BC94-080009EBBC58")
RfcContext;
#endif

EXTERN_C const CLSID CLSID_RfcContextSource;

#ifdef __cplusplus

class DECLSPEC_UUID("63bccfc0-5079-11d1-bca6-080009ebbc58")
RfcContextSource;
#endif

EXTERN_C const CLSID CLSID_RfcSchemaSource;

#ifdef __cplusplus

class DECLSPEC_UUID("176D2001-EF2F-11d1-ADC1-080009D213D2")
RfcSchemaSource;
#endif

EXTERN_C const CLSID CLSID_SAPTxStart;

#ifdef __cplusplus

class DECLSPEC_UUID("499ae4e0-5079-11d1-bca6-080009ebbc58")
SAPTxStart;
#endif

EXTERN_C const CLSID CLSID_RfcGuiSink;

#ifdef __cplusplus

class DECLSPEC_UUID("0C0F1283-6027-11D1-B766-00A0C9308BE6")
RfcGuiSink;
#endif

EXTERN_C const CLSID CLSID_SapRfcMonitor;

#ifdef __cplusplus

class DECLSPEC_UUID("8D24EDF3-BFFE-11D1-9046-0060974A3808")
SapRfcMonitor;
#endif

EXTERN_C const CLSID CLSID_RfcSession;

#ifdef __cplusplus

class DECLSPEC_UUID("25B93FB1-6FE5-11d2-940F-00600892A3A2")
RfcSession;
#endif
#endif /* __IRFC32Lib_LIBRARY_DEFINED__ */

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


