

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat May 26 11:29:11 2018
 */
/* Compiler settings for bibtechnology.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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


#ifndef __bibtechnology_h_h__
#define __bibtechnology_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Ibibtechnology_FWD_DEFINED__
#define __Ibibtechnology_FWD_DEFINED__
typedef interface Ibibtechnology Ibibtechnology;

#endif 	/* __Ibibtechnology_FWD_DEFINED__ */


#ifndef __bibtechnology_FWD_DEFINED__
#define __bibtechnology_FWD_DEFINED__

#ifdef __cplusplus
typedef class bibtechnology bibtechnology;
#else
typedef struct bibtechnology bibtechnology;
#endif /* __cplusplus */

#endif 	/* __bibtechnology_FWD_DEFINED__ */


#ifndef __ICOMSETTING_FWD_DEFINED__
#define __ICOMSETTING_FWD_DEFINED__
typedef interface ICOMSETTING ICOMSETTING;

#endif 	/* __ICOMSETTING_FWD_DEFINED__ */


#ifndef __COMSETTING_FWD_DEFINED__
#define __COMSETTING_FWD_DEFINED__

#ifdef __cplusplus
typedef class COMSETTING COMSETTING;
#else
typedef struct COMSETTING COMSETTING;
#endif /* __cplusplus */

#endif 	/* __COMSETTING_FWD_DEFINED__ */


#ifndef __ITempControl_FWD_DEFINED__
#define __ITempControl_FWD_DEFINED__
typedef interface ITempControl ITempControl;

#endif 	/* __ITempControl_FWD_DEFINED__ */


#ifndef __TempControl_FWD_DEFINED__
#define __TempControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class TempControl TempControl;
#else
typedef struct TempControl TempControl;
#endif /* __cplusplus */

#endif 	/* __TempControl_FWD_DEFINED__ */


#ifndef __ISpeedControl_FWD_DEFINED__
#define __ISpeedControl_FWD_DEFINED__
typedef interface ISpeedControl ISpeedControl;

#endif 	/* __ISpeedControl_FWD_DEFINED__ */


#ifndef __SpeedControl_FWD_DEFINED__
#define __SpeedControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpeedControl SpeedControl;
#else
typedef struct SpeedControl SpeedControl;
#endif /* __cplusplus */

#endif 	/* __SpeedControl_FWD_DEFINED__ */


#ifndef __ILogin_FWD_DEFINED__
#define __ILogin_FWD_DEFINED__
typedef interface ILogin ILogin;

#endif 	/* __ILogin_FWD_DEFINED__ */


#ifndef __Login_FWD_DEFINED__
#define __Login_FWD_DEFINED__

#ifdef __cplusplus
typedef class Login Login;
#else
typedef struct Login Login;
#endif /* __cplusplus */

#endif 	/* __Login_FWD_DEFINED__ */


#ifndef __IChangePassword_FWD_DEFINED__
#define __IChangePassword_FWD_DEFINED__
typedef interface IChangePassword IChangePassword;

#endif 	/* __IChangePassword_FWD_DEFINED__ */


#ifndef __ChangePassword_FWD_DEFINED__
#define __ChangePassword_FWD_DEFINED__

#ifdef __cplusplus
typedef class ChangePassword ChangePassword;
#else
typedef struct ChangePassword ChangePassword;
#endif /* __cplusplus */

#endif 	/* __ChangePassword_FWD_DEFINED__ */


#ifndef __IChooseHeater_FWD_DEFINED__
#define __IChooseHeater_FWD_DEFINED__
typedef interface IChooseHeater IChooseHeater;

#endif 	/* __IChooseHeater_FWD_DEFINED__ */


#ifndef __ChooseHeater_FWD_DEFINED__
#define __ChooseHeater_FWD_DEFINED__

#ifdef __cplusplus
typedef class ChooseHeater ChooseHeater;
#else
typedef struct ChooseHeater ChooseHeater;
#endif /* __cplusplus */

#endif 	/* __ChooseHeater_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __bibtechnology_LIBRARY_DEFINED__
#define __bibtechnology_LIBRARY_DEFINED__

/* library bibtechnology */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_bibtechnology;

#ifndef __Ibibtechnology_DISPINTERFACE_DEFINED__
#define __Ibibtechnology_DISPINTERFACE_DEFINED__

/* dispinterface Ibibtechnology */
/* [uuid] */ 


EXTERN_C const IID DIID_Ibibtechnology;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC0FC0B3-4E42-4A76-A5DF-AE4216F73ACF")
    Ibibtechnology : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IbibtechnologyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Ibibtechnology * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Ibibtechnology * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Ibibtechnology * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Ibibtechnology * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Ibibtechnology * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Ibibtechnology * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Ibibtechnology * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IbibtechnologyVtbl;

    interface Ibibtechnology
    {
        CONST_VTBL struct IbibtechnologyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Ibibtechnology_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Ibibtechnology_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Ibibtechnology_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Ibibtechnology_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Ibibtechnology_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Ibibtechnology_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Ibibtechnology_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Ibibtechnology_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_bibtechnology;

#ifdef __cplusplus

class DECLSPEC_UUID("F80D09B9-02CB-4991-86C5-5A91B6E64D9B")
bibtechnology;
#endif

#ifndef __ICOMSETTING_DISPINTERFACE_DEFINED__
#define __ICOMSETTING_DISPINTERFACE_DEFINED__

/* dispinterface ICOMSETTING */
/* [uuid] */ 


EXTERN_C const IID DIID_ICOMSETTING;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("18484DAC-CA0A-44EA-B71B-5968923276EB")
    ICOMSETTING : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ICOMSETTINGVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICOMSETTING * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICOMSETTING * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICOMSETTING * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICOMSETTING * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICOMSETTING * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICOMSETTING * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICOMSETTING * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ICOMSETTINGVtbl;

    interface ICOMSETTING
    {
        CONST_VTBL struct ICOMSETTINGVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOMSETTING_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICOMSETTING_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICOMSETTING_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICOMSETTING_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICOMSETTING_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICOMSETTING_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICOMSETTING_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICOMSETTING_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_COMSETTING;

#ifdef __cplusplus

class DECLSPEC_UUID("37021A54-8D33-4431-A0E1-24A6D920CB6D")
COMSETTING;
#endif

#ifndef __ITempControl_DISPINTERFACE_DEFINED__
#define __ITempControl_DISPINTERFACE_DEFINED__

/* dispinterface ITempControl */
/* [uuid] */ 


EXTERN_C const IID DIID_ITempControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("57B0CB89-518B-4068-BB13-F03698A978F0")
    ITempControl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITempControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITempControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITempControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITempControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITempControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITempControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITempControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITempControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITempControlVtbl;

    interface ITempControl
    {
        CONST_VTBL struct ITempControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITempControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITempControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITempControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITempControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITempControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITempControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITempControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITempControl_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TempControl;

#ifdef __cplusplus

class DECLSPEC_UUID("D31737E0-F457-4D84-89C7-1920898988A8")
TempControl;
#endif

#ifndef __ISpeedControl_DISPINTERFACE_DEFINED__
#define __ISpeedControl_DISPINTERFACE_DEFINED__

/* dispinterface ISpeedControl */
/* [uuid] */ 


EXTERN_C const IID DIID_ISpeedControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CA8A0BF4-26DB-466D-93CD-3C5B8C25D90D")
    ISpeedControl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISpeedControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpeedControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpeedControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpeedControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISpeedControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISpeedControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISpeedControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeedControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISpeedControlVtbl;

    interface ISpeedControl
    {
        CONST_VTBL struct ISpeedControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeedControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeedControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeedControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeedControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeedControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeedControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeedControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISpeedControl_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SpeedControl;

#ifdef __cplusplus

class DECLSPEC_UUID("046883B2-5CA4-458C-B883-FE4B29A3BC2F")
SpeedControl;
#endif

#ifndef __ILogin_DISPINTERFACE_DEFINED__
#define __ILogin_DISPINTERFACE_DEFINED__

/* dispinterface ILogin */
/* [uuid] */ 


EXTERN_C const IID DIID_ILogin;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("90FF90C4-4246-4B11-B443-8DA2656C586C")
    ILogin : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILoginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILogin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILogin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILogin * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILogin * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILogin * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILogin * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILogin * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILoginVtbl;

    interface ILogin
    {
        CONST_VTBL struct ILoginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILogin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILogin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILogin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILogin_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILogin_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILogin_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILogin_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILogin_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Login;

#ifdef __cplusplus

class DECLSPEC_UUID("4EB895E5-ECA3-4523-A68B-6611D0DF2A92")
Login;
#endif

#ifndef __IChangePassword_DISPINTERFACE_DEFINED__
#define __IChangePassword_DISPINTERFACE_DEFINED__

/* dispinterface IChangePassword */
/* [uuid] */ 


EXTERN_C const IID DIID_IChangePassword;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("445EE986-6BE4-4226-8884-37F3DEFD3513")
    IChangePassword : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IChangePasswordVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChangePassword * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChangePassword * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChangePassword * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChangePassword * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChangePassword * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChangePassword * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChangePassword * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IChangePasswordVtbl;

    interface IChangePassword
    {
        CONST_VTBL struct IChangePasswordVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChangePassword_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChangePassword_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChangePassword_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChangePassword_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChangePassword_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChangePassword_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChangePassword_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IChangePassword_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ChangePassword;

#ifdef __cplusplus

class DECLSPEC_UUID("DF39DBA3-90CE-4978-BF60-7E432AC32CBA")
ChangePassword;
#endif

#ifndef __IChooseHeater_DISPINTERFACE_DEFINED__
#define __IChooseHeater_DISPINTERFACE_DEFINED__

/* dispinterface IChooseHeater */
/* [uuid] */ 


EXTERN_C const IID DIID_IChooseHeater;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5D68FE0F-CE36-478D-9EFD-D90B7AC23EB4")
    IChooseHeater : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IChooseHeaterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChooseHeater * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChooseHeater * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChooseHeater * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChooseHeater * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChooseHeater * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChooseHeater * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChooseHeater * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IChooseHeaterVtbl;

    interface IChooseHeater
    {
        CONST_VTBL struct IChooseHeaterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChooseHeater_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChooseHeater_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChooseHeater_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChooseHeater_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChooseHeater_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChooseHeater_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChooseHeater_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IChooseHeater_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ChooseHeater;

#ifdef __cplusplus

class DECLSPEC_UUID("60033C16-0399-422C-97C1-15F7BF9E5AED")
ChooseHeater;
#endif
#endif /* __bibtechnology_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


