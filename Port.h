#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Dio Module Id */
#define PORT_MODULE_ID    (120U)

/* Dio Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#include "Common_Macros.h"
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != POTR_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Init */
#define PORT_INIT_SID                        (uint8)0x00

/* Service ID for PORT Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID           (uint8)0x01

/* Service ID for PORT Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID      (uint8)0x02

/* Service ID for PORT Get Version Info */
#define PORT_GET_VERSION_INFO_SID            (uint8)0x03

/* Service ID for PORT Set Pin Mode  */
#define PORT_SET_PIN_MODE_SID                (uint8)0x04


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report Invalid Port Pin ID Requested */
#define PORT_E_PARAM_PIN                     (uint8)0x0A

/* DET code to report that Port Pin not configured as changeable  */
#define PORT_E_DIRECTION_UNCHANGEABLE        (uint8)0x0B

/* DET code to report that API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                  (uint8)0x0C

/* DET code to report Invalid Mode */
#define PORT_E_PARAM_INVALID_MODE            (uint8)0x0D

/* DET code to report that PORT API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE             (uint8)0x0E

/* DET code to report that PORT API service called without module initialization */
#define PORT_E_UNINIT                        (uint8)0x0F

/* DET code to report that PORT APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                 (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Type definition for PORT pin*/
typedef uint8 Port_PinType;

/*Type definition for PORT pin mode*/
typedef uint8 Port_PinModeType;

/*Type definition for PORT pin level*/
typedef uint8 Port_PinLevelType;

/*Type definition for PORT port type*/
typedef uint8 Port_PortType;

/*Type definition for PORT direction type*/
typedef uint8 Port_PinDirectionType;

/*Type definition for PORT status type*/
typedef uint8 Port_PortStatusType;

/*Enum for changeable/non-changeable direction */
typedef enum {
    NON_CHANGEABLE_DIRECTION,CHANGEABLE_DIRECTION
}Port_PinDirectionChangeable;

/*Enum for changeable/non-changeable mode */
typedef enum {
    NON_CHANGEABLE_MODE,CHANGEABLE_MODE
}Port_PinModeChangeable;


/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirection;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Enum for pin mode groups  */
typedef enum
{
    PORT_PIN_MODE_AIN   = (uint8)10,
    PORT_PIN_MODE_DIO   = (uint8)0,
    PORT_PIN_MODE_ALT1  = (uint8)1,
    PORT_PIN_MODE_ALT2  = (uint8)2,
    PORT_PIN_MODE_ALT3  = (uint8)3,
    PORT_PIN_MODE_ALT4  = (uint8)4,
    PORT_PIN_MODE_ALT5  = (uint8)5,
    PORT_PIN_MODE_ALT6  = (uint8)6,
    PORT_PIN_MODE_ALT7  = (uint8)7,
    PORT_PIN_MODE_ALT8  = (uint8)8,
    PORT_PIN_MODE_ALT9  = (uint8)9,
    PORT_PIN_MODE_ALT10 = (uint8)10,
    PORT_PIN_MODE_ALT11 = (uint8)11,
    PORT_PIN_MODE_ALT12 = (uint8)12,
    PORT_PIN_MODE_ALT13 = (uint8)13,
    PORT_PIN_MODE_ALT14 = (uint8)14,
}Port_PinModeGroup;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirection direction;
    Port_InternalResistor resistor; //applicable only for input pins
    uint8 initial_value;            //applicable only for output pins
    Port_PinModeGroup pin_mode;
    Port_PinDirectionChangeable pin_direction_changeable;
    Port_PinModeChangeable  pin_mode_changeable;
}Port_ConfigPin;

/*Structure for initializing all pins */
typedef struct
{
    Port_ConfigPin Port_Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/*****************************************************************************************
 *                                External Variables                                    *
 *****************************************************************************************/

/*Post-build struct which initializes all pins configurations*/
extern const Port_ConfigType Port_PinConfiguration;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void);

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#endif /* PORT_H */
