/******************************************************************************/
/* File   : NvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgNvM.hpp"
#include "NvM_core.hpp"
#include "infNvM_Exp.hpp"
#include "infNvM_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NVM_AR_RELEASE_VERSION_MAJOR                                           4
#define NVM_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(NVM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible NVM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(NVM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible NVM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_NvM:
      INTERFACES_EXPORTED_NVM
      public abstract_module
   ,  public class_NvM_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

   public:
      FUNC(void, NVM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, NVM_CONFIG_DATA, NVM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, NVM_CODE) DeInitFunction (void);
      FUNC(void, NVM_CODE) MainFunction   (void);
      NVM_CORE_FUNCTIONALITIES
};

extern VAR(module_NvM, NVM_VAR) NvM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, NVM_VAR, NVM_CONST) gptrinfEcuMClient_NvM = &NvM;
CONSTP2VAR(infDcmClient,  NVM_VAR, NVM_CONST) gptrinfDcmClient_NvM  = &NvM;
CONSTP2VAR(infSchMClient, NVM_VAR, NVM_CONST) gptrinfSchMClient_NvM = &NvM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_NvM, NVM_VAR) NvM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include <cstring>
#include "CfgGen.hpp"
FUNC(void, NVM_CODE) module_NvM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, NVM_CONFIG_DATA, NVM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == NvM_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }

      if(FALSE){
         memcpy(
               (      void*)&CfgGen_NvM
            ,  (const void*)&CfgGen_Fls
            ,  sizeof(CfgGen_Type)
         );
      }
      else{
         memcpy(
               (      void*)&CfgGen_NvM
            ,  (const void*)&PBcfgGen_ROM
            ,  sizeof(CfgGen_Type)
         );
      }

#if(STD_ON == NvM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(
   void
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == NvM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(
   void
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      //EcuM.CB_NotifyNvMJobEnd();
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
#if(STD_ON == NvM_InitCheck)
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::SetDataIndex(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::GetDataIndex(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetBlockProtection(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::GetErrorStatus(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetRamBlockStatus(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetBlockLockStatus(
   void
){
}

#include "infMemIf_NvM.hpp"

FUNC(void, NVM_CODE) module_NvM::CancelJobs(
   void
){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) module_NvM::ReadBlock(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WriteBlock(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::RestoreBlockDefaults(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::EraseNvBlock(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::CancelWriteAll(
   void
){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) module_NvM::InvalidateNvBlock(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::ReadPRAMBlock(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WritePRAMBlock(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::RestorePRAMBlockDefaults(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::ReadAll(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WriteAll(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::ValidateAll(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::JobEndNotification(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::JobErrorNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

