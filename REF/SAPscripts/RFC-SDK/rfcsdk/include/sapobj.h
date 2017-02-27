/*@(#)$Id: //bas/640_REL/src/include/sapobj.h#1 $ */


/*-----------------------------------------------------------------------------
 * R F C  S D K
 *
 * object adapter api for remote objects
 *
 * (c) Copyright SAP AG, Walldorf  1997
 *-----------------------------------------------------------------------------
 */


/*
 * @doc
 *
 * @module RFC Object Adapter API for Remote Objects  |
 *
 * API for managing remote ABAP/4 objects.
 *
 * The support for remote objects in RFC is done by implementing an object adapter for a given object
 * system ("object driver") The interface between the RFC kernel and the object driver is highly technical
 * and is not intended as an API for application programs. Application programs shall use the programming model
 * of the corresponding object system instead.
 *
 * SAP offers a standard COM/DCOM adapter. Additional object systems can be implemented.
 *
 * Object adapter and RFC library communicate by 2 sets of function pointers defined via the
 * structures <t RemObjDriver> and <t RfcDriverCallBack>. Installing these functions is done 
 * by the functions <f RemObjInstallDriver> and <f RfcGetDriverCallBack>.
 *
 * RFC connections are managed using the usual RFC API functions like <f RfcOpenEx> etc.
 * 
 * The RFC Object Adapter API separates object management, which is done by the RFC API, from the actual
 * object model, implemented by the object driver.
 *
 * The object adapter assumes a simple object model, where objects are instances from classes and consist
 * of attributes, methods and interfaces. The object adapter does not assume inheritance relationships 
 * between classes, but they can be implemented, if needed (cast operation not yet defined!).
 *
 * Methods are indentified by (unicode) strings, Optionally they can also be identified by some numbers
 * being unique within the class or interface. Method parameters are input or output parameters or both.
 * Parameters can be identified by name or by position. Optional parameters can be implemented.
 * Parameter data types must be - at the adapter API level - RFC data types and the object driver must define
 * some mapping between the internal data types and the RFC data types.
 *
 * The supported RFC data types (<t RFCTYPE>) consists of a set of scalar data types ( single byte character  
 * field (any code set), wide character (unicode), raw date, 4-byte integer, 8-byte IEEE floating point, 
 * a fixed-point decimal number using BCD encoding, date and time fields and an object reference of the 
 * corresponding object system).
 *
 * These scalar types can be put together to structures and tables of structures, where we are only supporting
 * flat, non-nested data structures and strúctures and tables can not yet contain object references or tables.
 *
 * The object driver must implement some functions that allow the life time management of object references
 * from the RFC library. To allow an effective memory menagement the object driver is also responsible to
 * allocate the stub data structures RFC needs to manage object references, so that the driver can allocate
 * the RFC stub structures and its own additional data in one step.
 *
 * Additionally the RFC library offers several functions for accessing the object management tables of RFC.
 *
 * @flag <f RemObjGetObject> | 
 *  retrieves an object registered with RFC.
 * 
 * @flag <f RemObjRegisterObject> | 
 *  registers an object for use in RFC. 
 *  allows preallocating objects with special ids
 *  or using different transporting mechanisms 
 *  for marshaled object ids than RFC directly.
 *
 * @flag <f RemObjReleaseObject> | 
 *  Removes an object from the RFC management.
 *
 * @comm
 * To be used within Object Adapters. Not for public use.
 *
 * This is not the final version of the RFC object adapter
 * API. It will surely change in the next weeks and months again.
 */


#ifndef SAPRFC_H
#include "saprfc.h"
#endif

#ifndef SAPOBJ_H
#define SAPOBJ_H

#ifdef SAPonNT
#ifndef __midl
#include <oaidl.h>
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define REMOBJ_MESSAGE_SIZE 256
typedef SAP_UC RemObjMessage[REMOBJ_MESSAGE_SIZE];

/*
 * @enum REMOBJ_REGISTER_MODE |
 *
 * switch for function <f RemObjRegisterObject>.
 */
typedef enum
{
   REMOBJ_REGISTER_GLOBAL,   /* @emem register object globally 
			      * (default) 
			      */
   REMOBJ_REGISTER_CONTEXT   /* @emem register object in local context
                              * in a multi context environment as
			      * sapgui.
			      */
}
REMOBJ_REGISTER_MODE;

/*
 * never change these values, part of RFC protocoll!
 *
 * @enum RFCPARAM |
 *
 * bits describing method parameters.
 */
typedef enum 
{
        RFCPAR_NOTSET            = 0,    
	RFCPAR_FUNCTION_INPUT    = 1,      /* @emem input parameter */ 
	RFCPAR_FUNCTION_OUTPUT   = 2,      /* @emem output parameter */
	RFCPAR_FUNCTION_INOUT    = 3,      /* @emem changing parameter */
	RFCPAR_FUNCTION_RETURN   = 4,      /* @emem return parameter */
        RFCPAR_REF_TABLE         = 5,      /* @emem reference parameter (tables only) */
        RFCPAR_EXCEPTION         = 6,      /* @emem exception */
        RFCPAR_ERRORMESSAGE      = 7       /* @emem errormessage */
}
RFCPARAM;


/*
 * @enum RFCMETHODTYPE |
 *
 * bits describing method calls.
 */
typedef enum 
{
        RFC_FUNCTION        = 0,      /* @emem function module call (no method) */
        RFC_METHOD          = 1,      /* @emem method call */ 
        RFC_SET_ATTRIBUTE   = 2,      /* @emem attribute set operation */
        RFC_GET_ATTRIBUTE   = 4,      /* @emem attribute get operation */
        RFC_ONEWAY          = 8,      /* @emem call is oneway, no return */
        RFC_XML_FUNCTION    = 16,     /* @emem embeded xml function call */

        /* flag mask */
        RFCMETHODTYPE_FLAGS = RFC_ONEWAY
}
RFCMETHODTYPE;




/*
 * @enum XDRV_EXECUTION |
 *
 * is the method call executed inline or by an external interpreter?
 */
typedef enum
{
   XDRV_EXECUTION_INLINE,    /* @emem Inline execution. 
			      * Method is called during the send/receive
			      * operation.
			      */
   XDRV_EXECUTION_EXTERNAL   /* @emem External execution.
                              * Method must be called after the receive operation.
			      * Additional send operation after call.
			      */
}
XDRV_EXECUTION;

/*
 * @enum RFCTYPETAG |
 *
 * tag for <t RFCTYPE_INFO>.
 */
typedef enum 
{
    TYPETAG_NONE = 0,       /* @emem tag not set, invalid structure     */
    TYPETAG_SCALAR,         /* @emem a scalar field                     */
    TYPETAG_BCD,            /* @emem a bcd field with decimals          */
    TYPETAG_STRUCT_UUID,    /* @emem a structure UUID */
    TYPETAG_TYPEHANDLE,     /* @emem a type handle (<f RfcInstallStructure>) */
    TYPETAG_STRUCT_HINT,    /* @emem a structure using a structure hint */
    TYPETAG_STRUCT_RUDI     /* @emem a structure with a ABAP type handle
                             * (internal use only)
                             */
}
RFCTYPETAG;


/*
 * @enum RFCTYPEOCCURS |
 *
 * occurs value.
 */
typedef enum 
{
    TYPEOCCURS_SINGLE = 0,         /* @emem single field  */
    TYPEOCCURS_TABLE  = (-1)       /* @emem (unbounded) table  */
}
RFCTYPEOCCURS;
/*
 * @type RFCTYPE_INFO |
 *
 * type for <f XDRV_METHOD_RECEIVE_PARAMETER>.
 */
typedef struct
{
   RFCTYPETAG      typetag;       /* @field tag (<t RFCTYPETAG>). 
                                   * Depending on these value decimals or
                                   * structure id or handle are set.
                                   */
   RFCTYPEOCCURS   occurs;        /* @field occurs (<t RFCTYPEOCCURS>).
                                   * tells if field is a single field or
                                   * table
                                   */
   RFCTYPE         rfctype;       /* @field RFC type (<t RFCTYPE>). 
                                   * Set if <e RFCTYPE_INFO.typetag> is not
                                   * <e RFCTYPETAG.TYPETAG_NONE>.
                                   */
   SAP_UINT        length;        /* @field length in bytes 		*/

   SAP_UINT        decimals;      /* @field decimals for BCD fields.
                                   * (only set with <e RFCTYPETAG.TYPETAG_BCD>).
                                   */
   union
   {
        SAP_UUID        structId;      /* @field structure id for records  
                                       * (only set with <e RFCTYPETAG.TYPETAG_STRUCT>).
                                       */
        RFC_TYPEHANDLE  typeHandle;   /* @field structure handle for records
                                       * (only set with <e RFCTYPETAG.TYPETAG_STRUCT>,
                                       * may be set to scalar types as <e RFCTYPE.RFCTYPE_CHAR> or
                                       * <e RFCTYPE.RFCTYPE_BYTE>).
                                       */
        void *          structHint;    /* @field structure hint record */
        SAP_UINT        pRudi[2];      /* @field an ABAP type handle (internal use only) */
   }
   u;

   void *          _reserve1[3];
}
RFCTYPE_INFO;


typedef RFCTYPE_INFO * PRFCTYPE_INFO; 

/* exported functions */

/*---------------------------------------------------------------------
 @func
 
 RemObjReleaseObject releases an formerly registered
 object from the RFC object management.
 
 The release hook function of the corresponding
 object adapter is called internally.

 @comm
 Internal use only.
--------------------------------------------------------------------*/
void  SAP_API RemObjReleaseObject  ( 
    RFC_HANDLE           hrfc,  /* @parm handle to open RFC connection */
    SAP_UUID          *  pUUID  /* @parm id of the object to release   */
  );


/*---------------------------------------------------------------------
 @func
 
  RemObjGetObject gives back the address of an object
  formerly registered with <f RemObjRegisterObject>.
  
  If the ID is all zero, a NULL pointer is returned.
 
 @comm
  Internal use only.

  @rdesc
  
  returns
  @flag <e RFC_RC.RFC_OK>  |
        The object was found and the given object type
        is right.
  @flag <e RFC_RC.RFC_FAILURE> |
        The object is not registered or the given type
        is wrong.

 --------------------------------------------------------------------*/
RFC_RC SAP_API RemObjGetObject      ( 
     RFC_HANDLE           hrfc,         /* @parm handle to RFC connection    */
     SAP_UUID          *  pUUID,        /* @parm id of the object            */
     RFCTYPE              objectType,   /* @parm object type ( <t RFCTYPE> ) */
     void             **  pObject       /* @parm output: pointer to object   */
     );


/*---------------------------------------------------------------------
 @func
 
 Register an object under an given ID.
 Object can be retrieved then by <f RemObjGetObject>.
 
 <t SAP_UUID> can be any UUID generated by an RPC UUID generator
 or the function module SYSTEM_GET_UNIQUE_ID in R/3.
 
 Depending on the value of 'mode' the lifetime of the object
 is correlated to the lifetime of the RFC connection 
 (<e REMOBJ_REGISTER_MODE.REMOBJ_REGISTER_GLOBAL> ) 
 or to the lifetime of the calling
 context/roll area 
 (<e REMOBJ_REGISTER_MODE.REMOBJ_REGISTER_CONTEXT>).
 
 As soon as the lifetime ends the release function of the
 installed object adapter is called to release the object.
 The object is then removed from the RFC object table.

 @comm
 Internal use only.
  
 @rdesc
  
 returns
  @flag <e RFC_RC.RFC_OK>  |
     successfully registered.

  @flag <e RFC_RC.RFC_FAILURE> |
     cannot register (no memory or object already there).
--------------------------------------------------------------------*/
RFC_RC SAP_API RemObjRegisterObject ( 
     RFC_HANDLE           hrfc,       /* @parm handle to open RFC connection */
     void              *  object,     /* @parm pointer to object             */
     RFCTYPE              objectType, /* @parm object type (<t RFCTYPE>).
                                       * a corresponding object adapter has
                                       * to be installed.
                                       */
     SAP_UUID          *  pUUID,      /* @parm id of the object */
     REMOBJ_REGISTER_MODE mode        /* @parm mode, how to register 
                                       * (<t REMOBJ_REGISTER_MODE>) 
                                       */
     );


/* RotStub ... is be replaced with RemObjStub... */
struct _RotStubStruct;
typedef struct _RotStubStruct * RemObjStub;	

typedef void * RemObj;

/*---------------------------------------------------------------------
 @type RemObjStub |

 is a pointer to <t RemObjStubStruct>
---------------------------------------------------------------------*/

/*---------------------------------------------------------------------
 @type RemObj |

 is a pointer to any object.
---------------------------------------------------------------------*/

typedef void * RotHandle;

/*---------------------------------------------------------------------

 @struct RemObjStubStruct |
 
 minimal structure for a stub.
---------------------------------------------------------------------*/
typedef struct _RotStubStruct
{
    const void  * tag;
    SAP_UUID      id;
    RotHandle     rotHandle;
    wchar_t     * name;
    void        * addr;     /* @field address of the object the
                             * stub points to.
                             */
    RFCTYPE       type;
    RemObjStub    parent, child, prev, next;
    unsigned      _reserve[4];
}
RotStubStruct;

typedef RotStubStruct RemObjStubStruct;

#define REMOBJDRV_VERSION 1
#define REMOBJDRV_SIZE    sizeofR( RemObjDriver )


/*--------------------------------------------------------------------
 @cb RemObjStub | XDRV_ALLOC_STUB |

 allocate a new stub.

 @comm
 Internal use only.

 @rdesc
 must return a pointer to memory at least of size 
 of <t RemObjStubStruct> or NULL.
--------------------------------------------------------------------*/
typedef RemObjStub (DLL_CALL_BACK_FUNCTION_PTR XDRV_ALLOC_STUB ) ( void );

/*--------------------------------------------------------------------
 @cb void | XDRV_FREE_STUB |

 must free an allocated stub.

 @comm
 Internal use only.

 must be implemented if <t XDRV_ALLOC_STUB> is set, too.
--------------------------------------------------------------------*/
typedef void    (DLL_CALL_BACK_FUNCTION_PTR XDRV_FREE_STUB  ) 
( 
  RemObjStub ptr  /* @parm pointer to stub memory */
);

/*--------------------------------------------------------------------
 @cb int | XDRV_RELEASE |

 the object managed by the given stub shall be released.

 @comm
 Internal use only.

 @rdesc
 returns 0 for o.k. and 1 for error.
--------------------------------------------------------------------*/
typedef int     (DLL_CALL_BACK_FUNCTION_PTR XDRV_RELEASE    ) 
( 
    RemObjStub  stub  /* @parm pointer to stub memory */
);

/*--------------------------------------------------------------------
 @cb int | XDRV_ADDREF |

 Allways called, when RFC exports the object to the application.

 @comm
 Internal use only.

 @rdesc
 returns 0 for o.k. and 1 for error.
--------------------------------------------------------------------*/
typedef int     (DLL_CALL_BACK_FUNCTION_PTR XDRV_ADDREF     ) 
( 
    RemObjStub  stub /* @parm pointer to stub memory */
);

/*--------------------------------------------------------------------
 @cb int | XDRV_CREATE_PROXYSTUB |

 Create a proxy and its corresponding stub within 1 step.

 @comm
 Internal use only.

 @rdesc
 Returns 0 for o.k. and 1 for error.
--------------------------------------------------------------------*/
typedef int     (DLL_CALL_BACK_FUNCTION_PTR XDRV_CREATE_PROXYSTUB ) 
( 
 SAP_UUID  *   clsid,   /* @parm class id of proxy (may be NULL) */
 RFC_HANDLE    hrfc,    /* @parm handle to RFC connection, where
                         * the original object lives in
                         */
 RemObjStub   *   pProxyStub  /* @parm output: pointer to stub created */
);


/*--------------------------------------------------------------------
 @cb int | XDRV_CREATE_INSTANCE |

 Create a new instance of an object and attach it to stub.

 @comm
 Internal use only.

 @rdesc
 Returns 0 for o.k. and 1 for error.
--------------------------------------------------------------------*/
typedef int     ( DLL_CALL_BACK_FUNCTION_PTR XDRV_CREATE_INSTANCE ) 
( 
  wchar_t   *   name,     /* @parm class name */ 
  wchar_t   *   dest,     /* @parm optional destination (may be NULL) */
  wchar_t   *   ifName,   /* @parm interface name (may be NULL) */
  RFC_CHAR  *   message, /* @parm buffer for error message on failure */
  RemObjStub       stub      /* @parm stub to be used to attach object */
);

/*--------------------------------------------------------------------
 @cb int | XDRV_COPY_POINTER |

 Copy an object pointer. 
 Must be defined if an object pointer cannot be copied simply by
 moving the address.

 @comm
 Internal use only.

 @rdesc
 Returns 0 for o.k. and 1 for error or size mismatch.
--------------------------------------------------------------------*/
typedef int     (DLL_CALL_BACK_FUNCTION_PTR XDRV_COPY_POINTER)      
( 
  void *    targetAddr,   /* @parm target address, where object pointer
                           * shall be moved to.
                           */
  unsigned  targetLength, /* @parm length of target area in bytes.
                           */
  void *    source        /* @parm object pointer to copy.
                           */
);

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_RECEIVE_INIT |

 Initialize a method call (receiver).

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_RECEIVE_INIT)
(
  RFC_HANDLE     hRfc,     /* @parm [in]  handle */
  RemObjStub     stub,     /* @parm [in]  stub used */
  RFCMETHODTYPE  mType,    /* @parm [in]  method type */ 
  wchar_t *      wname,    /* @parm [in]  method name as UNICODE string */
  RFC_INT        dispid,   /* @parm [in]  dispid or DISPID_UNKNOWN */
  void **        ppCallCtx /* @parm [out] method call context */  
) ;

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_CALL_INIT |

 Initialize a method call (caller).

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_CALL_INIT)
(
  RFC_HANDLE     hRfc,          /* @parm [in]  handle */
  RFCTYPE        objectType,    /* @parm [in] object type */
  void *         objectAddress, /* @parm [in] object addres */
  unsigned       objectSize,    /* @parm [in] size of object pointer */
  RFCMETHODTYPE  mType,         /* @parm [in]  method type */ 
  wchar_t *      wname,         /* @parm [in]  method name as UNICODE string */
  RFC_INT        dispid,        /* @parm [in]  dispid or DISPID_UNKNOWN */
  void **        ppCallCtx      /* @parm [out] method call context */  
) ;

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_RECEIVE_PARAMETER |

 Set a parameter for the method call (receiver).

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_RECEIVE_PARAMETER)
(
  void *         pCallCtx, /* @parm [in]  method call context */  
  RFCPARAM       inout,    /* @parm [in]  input and/or output parameter */ 
  wchar_t *      name,     /* @parm [in]  parameter's name */
  RFC_INT        dispid,   /* @parm [in]  dispid or DISPID_UNKNOWN */
  int            position, /* @parm [in]  position of parameter or 
                            * <e METHOD_PARAMETER_POS.METHOD_PARAMETER_NO_POSITION>
			    */ 
  RFCTYPE_INFO * pType,    /* @parm [in,out]  parameter's type.
                            * Depending on the content the function can modify
                            * the type description. However, the object adapter
                            * does not support any conversions. The content only indicates
                            * how the data on the wire shall be intrepreted.
                            * If the <e RFCTYPE_INFO.typetag> field contains 
                            * <e RFCTYPETAG.TYPETAG_NONE>,
                            * only the <e RFCTYPE_INFO.lenght> field is filled with
                            * the length in bytes of the data on the wire and
                            * the function has to supply a vaild <t RFCTYPE_INFO>
                            * structure.
                            */
  void **        ppWhere   /* @parm [out] where to write (may be set to NULL) */
) ;

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_SEND_PARAMETER |

 Put a parameter on the wire.
 Either a name, a parameter id or a position must be given.
 
 A type description must be given also if the receiver doesn't assume
 self describing data. Calling function modules these information is
 not put on the wire because the then used RFC protocol doesn't understand
 these items.
 
 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_SEND_PARAMETER)
(
  void *         pCallCtx, /* @parm [in]  method call context */  
  RFCPARAM       inout,    /* @parm [in]  input and/or output parameter 
                            * (with respect to the called function or method).
                            */ 
  wchar_t *      name,     /* @parm [in]  parameter's name or NULL */
  RFC_INT        dispid,   /* @parm [in]  dispid or DISPID_UNKNOWN */
  int            position, /* @parm [in]  position of parameter or 
                            * <e METHOD_PARAMETER_POS.METHOD_PARAMETER_NO_POSITION>.
			    */ 
  RFCTYPE_INFO * pType,    /* @parm [in]  parameter's type (<t RFCTYPE_INFO>) */
  void         * pWhere    /* @parm [in]  address of value */
);

#ifndef DISPID_UNKNOWN
#define DISPID_UNKNOWN (-1)
#endif

/*
 * @enum METHOD_PARAMETER_POS |
 *
 * Parameter position field for function <f XDRV_METHOD_RECEIVE_PARAMETER>.
 */
enum
{
    METHOD_PARAMETER_NO_POSITION = (-1) /* @emem no position set */
};



/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_RECEIVE_DO |

 Method call (receiver).

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_RECEIVE_DO)
(
  void *                pCallCtx,     /* @parm [in]  method call context */  
  void *                pCallBackCtx, /* @parm [in]  context for call back
				       * function
				       */

  XDRV_METHOD_SEND_PARAMETER   fptr_return,  /* @parm [in]  
				       * function to return
				       * out/reference/return parameters
                                       * ( <t XDRV_METHOD_SEND_PARAMETER>).
				       */
  XDRV_EXECUTION      * pExecution,   /* @parm [out] execution mode */
  RFC_CHAR *            message       /* @parm [out] error message */
) ;

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_MOVE |

 Move/converts method parameter.

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_MOVE)
(
  void *                pCallCtx,     /* @parm [in]  method call context */  
  PRFCTYPE_INFO         pType         /* @parm [in]  parameter's type */
) ;


/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_METHOD_CALL_DO |

 Method call (caller).

 @comm
 Internal use only.

 @rdesc
 Returns <e RFC_RC.RFC_OK> for o.k. and a value not 0 for error.
--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_METHOD_CALL_DO)
(
  void *                pCallCtx,     /* @parm [in]  method call context */  
  void *                pCallBackCtx, /* @parm [in]  context for call back
				       * function
				       */
  XDRV_METHOD_RECEIVE_PARAMETER MethodParameter, /* @parm [in] called to pass
                                    * a returned method parameter
                                    * ( <f XDRV_METHOD_RECEIVE_PARAMETER> )
	                            */
  XDRV_MOVE             Move,       /* @parm [in] called to move the parameter. 
                                       * ( <f XDRV_MOVE> )
                                       */

  XDRV_EXECUTION        execution   /* @parm [in]  execution mode */
) ;



/*---------------------------------------------------------------------

 @struct RemObjDriver |
 
 Structure containing the several hook functions of an object adapter.

 @comm
 Internal use only.

---------------------------------------------------------------------*/
typedef const struct
{
    unsigned             version;  /* @field must be REMOBJDRV_VERSION */
    unsigned             size;     /* @field must be REMOBJDRV_SIZE    */     

    XDRV_ALLOC_STUB       allocStub; /* @field allocate a stub
                                     *
                                     * default behavior is to allocate
                                     * a standard stub structure.
                                     * ( <f XDRV_ALLOC_STUB> )
                                     */
    XDRV_FREE_STUB        freeStub;  /* @field free a stub allocated earlier 
                                     *
                                     * must be implemented, if allocStub is
                                     * not NULL.
                                     * ( <f XDRV_FREE_STUB> )
                                     */

    XDRV_RELEASE          release;   /* @field the object is released from RFC 
                                     *
                                     * default behavior: does nothing
                                     * ( <f XDRV_RELEASE> )
                                     */
    XDRV_ADDREF           addRef;    /* @field called always when RFC exports
                                     * the object to the application.
                                     *
                                     * default behavior: does nothing.
                                     * ( <f XDRV_ADDREF> )
                                     */

    XDRV_CREATE_PROXYSTUB createProxyStub;  /* @field create a proxy and its
                                     * corresponding stub in one step for the
                                     * given class id.
                                     *
                                     * default behavior: create standard stub
                                     * and return NULL to application.
                                     * ( <f XDRV_CREATE_PROXYSTUB> )
                                     */
    XDRV_CREATE_INSTANCE  createInstance;   /* @field create a new instance of
                                     * a given object class.
                                     *
                                     * default behavior: error message.
                                     * ( <f XDRV_CREATE_INSTANCE> )
                                     */

    XDRV_COPY_POINTER     copyPointer;      /* @field called if an object pointer
                                     * is copied to the application.
                                     *
                                     * default behavior: copy object pointers
                                     * as they are.
                                     * ( <f XDRV_COPY_POINTER> )
                                     */

    XDRV_METHOD_RECEIVE_INIT      MethodInit;   /* @field called to initialize 
                                     * a method call
                                     * ( <f XDRV_METHOD_RECEIVE_INIT> )
			             */
    XDRV_METHOD_RECEIVE_PARAMETER MethodParameter; /* @field called to pass
                                    * a method parameter
                                    * ( <f XDRV_METHOD_RECEIVE_PARAMETER> )
	                            */
    XDRV_METHOD_RECEIVE_DO      MethodCall; /* @field called to call a method 
                                       * ( <f XDRV_METHOD_RECEIVE_DO> )
                                       */
    XDRV_MOVE             Move;       /* @field called to move 
                                       * ( <f XDRV_MOVE> )
                                       */
}
RemObjDriver;

/*---------------------------------------------------------------------
 @func
 
 Install object adapter driver of given object type.

 An object adapter is a set of functions, which allows the management
 of any kind of object system within RFC.

 The set of functions is given by the structure <t RemObjDriver>.

 Internally for RFC an object is nothing but an entity of type 'void *'.
 There are several hook exits defined for an object adapter to modify
 and extend the standard behavior.
 
 The object adapter is the only part, which knows about the
 real nature of RFC objects. Within RFC an object is nothing
 but an address.

 Not all the hook functions must be implemented. If indicated you
 can pass also a NULL pointer.

 @comm
 Internal use only.
--------------------------------------------------------------------*/
void SAP_API RemObjInstallDriver( 
     RFCTYPE type,                 /* @parm type of object 
                                    * (cf. <t RFCTYPE>). 
                                    */
     RemObjDriver * driver         /* @parm pointer to hook 
                                    * functions.
                                    */
     );



/*--------------------------------------------------------------------
 @cb void | XDRV_ON_ERROR |

 Trace an error.

 @comm
 Internal use only.

 @ex Call the errortrace callback always by using the macro OnErrorInfo: |

     RfcDriverCallBack * cb;
 
     cb->onError( OnErrorInfo( COM_CANNOT_DO_SOMETHING ), 
                  "error code %d while doing %s", 10, "nothing" );
 

--------------------------------------------------------------------*/
typedef void (DLL_CALL_BACK_FUNCTION_PTR XDRV_ON_ERROR )
(
   RFC_CHAR   * errorCode, /* @parm RABAX-like error code as 
                        * "OBJECTDRIVER_CANNOT_DO_SOMETHING"
                        */
   RFC_CHAR     * fileName,  /* @parm should be sccsid + 4 or __FILE__ */
   unsigned line,            /* @parm should be __LINE__        */
   RFC_CHAR     * format,    /* @parm printf format + variables */
   ...                       /* @parmvar printf-like variables  */
);

/*--------------------------------------------------------------------
 @cb void | XDRV_TRACE |

 Trace.

 @comm
 Internal use only.

 @ex Call the trace callback always by using the macro TraceInfo: |

     RfcDriverCallBack * cb;

     cb->trace( TraceInfo, "%d %d", 1 , 2 );
 

--------------------------------------------------------------------*/
typedef void (DLL_CALL_BACK_FUNCTION_PTR XDRV_TRACE )
(
         RFC_CHAR   * fileName,  /* @parm should be sccsid + 4 or __FILE__ */
         unsigned     line,      /* @parm should be __LINE__        */
         RFC_CHAR   * format,    /* @parm printf format + variables */
         ...                     /* @parmvar printf-like variables  */
);


/*--------------------------------------------------------------------
 @cb void | XDRV_SET_TRACE |

 Set trace level.

 @comm
 Internal use only.

--------------------------------------------------------------------*/
typedef void (DLL_CALL_BACK_FUNCTION_PTR XDRV_SET_TRACE )
(
         int   level   /* @parm trace level */
);

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_PROXY_CREATE_INSTANCE |

 create an Remote Object instance remotely.

 @comm
 Internal use only.

--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_PROXY_CREATE_INSTANCE )
( 
        RFC_HANDLE  hrf,       /* @parm [in]  handle to RFC connection */
        wchar_t   * name,      /* @parm [in]  class name */
        wchar_t   * ifName,    /* @parm [in]  interface name */
        SAP_UUID  * pId,       /* @parm [in]  id in remote object table */
        unsigned    proxyLeng, /* @parm [in]  length of proxy pointer */
        RFCTYPE     proxyType, /* @parm [in]  proxy type ( =driver type ) */
        RFC_CHAR  * message,   /* @parm [out] message buffer (may be NULL)
                                */
        RemObj    * pProxy     /* @parm [out] pointer to proxy object
                                * (may be NULL)
                                */
);

/*--------------------------------------------------------------------
 @cb RFC_RC | XDRV_CALL_RECEIVE_VALUES |

 start receive return values.

 @comm
 Internal use only.

--------------------------------------------------------------------*/
typedef RFC_RC (DLL_CALL_BACK_FUNCTION_PTR XDRV_CALL_RECEIVE_VALUES )
(
        void *       pCallCtx,	   /* @parm [in]  call context */
	void *       pCallBackCtx, /* @parm [in]  context for receive */
	XDRV_METHOD_RECEIVE_PARAMETER MethodParameter,	/* @parm [in]  
	                            * function to receive a parameter 
                                    * ( <f XDRV_METHOD_RECEIVE_PARAMETER> ).
				    */
	XDRV_MOVE    Move	   /* @parm [in]  do something after 
	                            * the parameter is received
                                    * ( <f XDRV_MOVE> ).
				    */
);



/*-----------------------------------------------------------------

 @struct RfcDriverCallBack |

 structure containing the call back functions an object adapter
 can use

 @comm
 Internal use only.
 
 The error and trace functions shall be called by

 RfcDriverCallBack * cb;

    cb->onError( OnErrorInfo( COM_CANNOT_DO_SOMETHING ), 
                   "error code %d while doing %s", 10, "nothing" );

    cb->trace( TraceInfo, "%d %d", 1 , 2 );

 The macros OnErrorInfo and TraceInfo assume that the actual file 
 contains a static variable
 'static rfc_char_t * sccsid = "@(#)<lt>filename<gt> ...."' and you are 
 using SCCS as source code management system. If not,  
 'sccsid' should at least contain the file name at offset 4, 
 may be as 
 'sccsid = "    " __FILE__;'.

-----------------------------------------------------------------*/
typedef const struct
{
    XDRV_ON_ERROR onError; /* @field error trace function 
                            * (<f XDRV_ON_ERROR>)
                            */
    XDRV_TRACE    trace;   /* @field standard trace function 
                            * (<f XDRV_TRACE>)
                            */
    XDRV_PROXY_CREATE_INSTANCE createInstance;  /* @field 
                            * create an instance remotely 
                            * (<f XDRV_PROXY_CREATE_INSTANCE>).
                            */
    XDRV_SET_TRACE settrace; /* @field set trace level 
                              * (<f XDRV_SET_TRACE>).
                              */

    XDRV_METHOD_CALL_INIT      MethodInit;   /* @field called to initialize 
                                     * a method call
                                     * ( <f XDRV_METHOD_CALL_INIT> )
			             */
    XDRV_METHOD_SEND_PARAMETER MethodParameter; /* @field called to pass
                                    * a method parameter
                                    * ( <f XDRV_METHOD_SEND_PARAMETER> )
	                            */
    XDRV_METHOD_CALL_DO        MethodCall; /* @field called to call a method 
                                       * ( <f XDRV_METHOD_CALL_DO> )
                                       */
    XDRV_CALL_RECEIVE_VALUES   ReceiveValues; /* @field must be called to 
				       * receive the parameters if the
				       * function isn't called in 
				       * <e XDRV_EXECUTE.XDRV_EXECUTION_INLINE>
				       * mode ( <f XDRV_CALL_RECEIVE_VALUES> ).
				       */
}
RfcDriverCallBack;

#define RFCDRIVERCALLBACK_VERSION 1
#define RFCDRIVERCALLBACK_SIZE    sizeofR( RfcDriverCallBack ) 


#define OnErrorInfo( string )   # string, sccsid + 4, __LINE__         /* for all c++ and non-kernel c sources */ 
#define OnErrorInfoU( string )  cU(# string), sccsidU + 4, __LINE__    /* for  kernel c sources*/

#define TraceInfo               sccsid + 4, __LINE__

/*---------------------------------------------------------------------
 @func
 
 Retrieve a call back interface for an object adapter driver
 to use internal functionality of the RFC library.

 @comm
 Internal use only.
--------------------------------------------------------------------*/
void SAP_API RfcGetDriverCallBack 
( 
  unsigned  version,             /* @parm must be RFCDRIVERCALLBACK_VERSION */
  unsigned  size,                /* @parm must be RFCDRIVERCALLBACK_SIZE */    
  RfcDriverCallBack ** pCallBack /* @parm output: pointer to callback interface 
                                  * <t RfcDriverCallBack>. */
);


/*-------------------------------------------------------------------
 @type SAP_UUID |
 
 corresponds to a UUID or GUID defined in RPC or COM
-------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* c++ */

#endif /* SAPOBJ_H */
