/*===================================================================================*/
/*************************************************************************************/
/**
 * @file      coco_std_api.h
 * @brief     COCO Standard public header
 * @details   The COCO Standard defines a common set of structs and enums which can be
 *            used by both the OEM App and Client App to communicate with each other
 *            seamlessly. This file contains the declarations of public API's, enums and
 *            structs for the COCO Standard.
 * @see
 * @author    Varun Kumar, varun.k@healthasyst.com
 * @author    Prajeesh Prakasan, prajeeshprakash@elear.solutions
 *            Bala Krishna Kurmapu, balakrishna.kurmapu@healthasyst.com
 *            Kishori Patil, kishoripatil@elear.solutions
 *            Prasad Makireddy, prasadmakireddy@elear.solutions
 * @copyright Copyright (c) 2019-2020 Elear Solutions Tech Private Limited. All rights
 *            reserved.
 * @license   To any person (the "Recipient") obtaining a copy of this software and
 *            associated documentation files (the "Software"):
 *            All information contained in or disclosed by this software is
 *            confidential and proprietary information of Elear Solutions Tech
 *            Private Limited and all rights therein are expressly reserved.
 *            By accepting this material the recipient agrees that this material and
 *            the information contained therein is held in confidence and in trust
 *            and will NOT be used, copied, modified, merged, published, distributed,
 *            sublicensed, reproduced in whole or in part, nor its contents revealed
 *            in any manner to others without the express written permission of
 *            Elear Solutions Tech Private Limited.
 */
/*************************************************************************************/
/*===================================================================================*/
#ifndef COCO_STD_API_H_INCLUDED
#define COCO_STD_API_H_INCLUDED

/*************************************************************************************
 *                          INCLUDES                                                 *
 *************************************************************************************/
#include <stdint.h>
#include <time.h>

/*************************************************************************************
 *                          GLOBAL MACROS                                            *
 *************************************************************************************/
#ifndef threadLocal
# if __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
#  define threadLocal _Thread_local
# elif defined _WIN32 && ( \
       defined _MSC_VER || \
       defined __ICL || \
       defined __DMC__ || \
       defined __BORLANDC__ )
#  define threadLocal __declspec(thread)
/* note that ICC (linux) and Clang are covered by __GNUC__ */
# elif defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define threadLocal __thread
# else
#  error "Cannot define thread_local"
# endif
#endif

// IP address of the listening server running on the device to which COCO App will connect to
// during addition of WiFi device using Access Point mode
#define COCO_STD_ADD_WIFI_DEVICE_AP_IP     "10.22.0.1"

// Port of the listening server running on the device to which COCO App will connect to
// during addition of WiFi device using Access Point mode
#define COCO_STD_ADD_WIFI_DEVICE_AP_PORT   "21000"

// Macros to get struct members of coco_std_media_frame_packed_pkt_t
#define COCO_STD_GET_FRAME_INDEX(pkt)                            ((pkt)->frameIndex)
#define COCO_STD_GET_FRAME_TYPE(pkt)                             ((pkt)->frameType)
#define COCO_STD_GET_FRAME_DURATION(pkt)                         ((pkt)->frameDuration)
#define COCO_STD_GET_FRAME_PTS(pkt)                              ((pkt)->framePTS)
#define COCO_STD_GET_FRAME_SIZE(pkt)                             ((pkt)->frameSize)
#define COCO_STD_GET_FRAME_DATA(pkt)                             ((char *)((uint8_t *)(pkt) + \
                                                                           sizeof(coco_std_media_frame_packed_pkt_t)))

/*************************************************************************************
 *                          GLOBAL TYPEDEFS                                          *
 *************************************************************************************/
// Possible COCO Standard struct types
typedef enum {
  COCO_STD_STRUCT_TYPE_MIN = -1,
  COCO_STD_STRUCT_RESOURCE_SUMMARY,
  COCO_STD_STRUCT_CAPABILITY_INFO,
  COCO_STD_STRUCT_ATTRIBUTE_INFO,
  COCO_STD_STRUCT_RESOURCE_ENTITY,
  COCO_STD_STRUCT_ZONE_ENTITY,
  COCO_STD_STRUCT_SCENE_ENTITY,
  COCO_STD_STRUCT_RULE_ENTITY,
  COCO_STD_STRUCT_RULE_RES_COND,
  COCO_STD_STRUCT_RESRC_ACTION,
  COCO_STD_STRUCT_RULE_SCHEDULE_COND,
  COCO_STD_STRUCT_RULE_SCENE_ACT,
  COCO_STD_STRUCT_MESSAGE,
  COCO_STD_STRUCT_RESOURCE_ADVERTISE,
  COCO_STD_STRUCT_INFO_REQUEST,
  COCO_STD_STRUCT_INFO_RESPONSE,
  COCO_STD_STRUCT_ADDED_RESOURCE,
  COCO_STD_STRUCT_REMOVED_RESOURCE,
  COCO_STD_STRUCT_RESOURCE_CMD,
  COCO_STD_STRUCT_RESOURCE_CMD_STATUS,
  COCO_STD_STRUCT_DEVICE_CMD,
  COCO_STD_STRUCT_DEVICE_CMD_STATUS,
  COCO_STD_STRCUT_DEVICE_INFO,
  COCO_STD_STRUCT_FW_UPDATE_NOTIF,
  COCO_STD_STRUCT_ZONE_RESOURCE,
  COCO_STD_STRUCT_COCONET_CMD,
  COCO_STD_STRUCT_COCONET_CMD_STATUS,
  COCO_STD_STRUCT_ZONE_DELETED,
  COCO_STD_STRUCT_SCENE_DELETED,
  COCO_STD_STRUCT_RULE_DELETED,
  COCO_STD_STRUCT_SCENE_METADATA,
  COCO_STD_STRUCT_CAPABILITY,
  COCO_STD_STRUCT_ATTR_STATIONARY_POSITION_DEVICE_LOC, // It is the struct corresponding to COCO_STD_CAP_STATIONARY_POSITION
                                                       // and COCO_STD_ATTR_STATIONARY_POSITION_DEVICE_LOC attribute
  COCO_STD_STRUCT_ATTR_STATIONARY_POSITION_BEACON_LOC, // It is the struct corresponding to COCO_STD_CAP_STATIONARY_POSITION
                                                       // and COCO_STD_ATTR_STATIONARY_POSITION_BEACON_LOC attribute
  COCO_STD_STRUCT_ATTR_REAL_TIME_POSITION_BEACON_LOC,  // It is the struct corresponding to COCO_STD_CAP_REAL_TIME_POSITION
                                                       // and COCO_STD_ATTR_REAL_TIME_POSITION_BEACON_LOC attribute
  COCO_STD_STRUCT_TYPE_MAX,
  COCO_STD_STRUCT_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_struct_type_t;

// Possible power sources of a resource
typedef enum {
  COCO_STD_POWER_SRC_MIN = -1,
  COCO_STD_POWER_SRC_UNKNOWN,
  COCO_STD_POWER_SRC_MAINS_SINGLE_PHASE,
  COCO_STD_POWER_SRC_MAINS_3_PHASE,
  COCO_STD_POWER_SRC_MAINS_UNKNOWN_PHASE,
  COCO_STD_POWER_SRC_BATTERY,
  COCO_STD_POWER_SRC_DC_SOURCE,
  COCO_STD_POWER_SRC_EMERGENCY_CONST_POWER,
  COCO_STD_POWER_SRC_EMERGENCY_TRANSFER_SWITCH,
  COCO_STD_POWER_SRC_NOT_AVAILABLE,
  COCO_STD_POWER_SRC_MAX,
  COCO_STD_POWER_SRC_UBOUND = 0x7FFFFFFF
} coco_std_power_source_t;

// Possible receiver types of a resource
typedef enum {
  COCO_STD_RCVR_TYPE_MIN = -1,
  COCO_STD_RCVR_TYPE_RX_ON_WHEN_IDLE,
  COCO_STD_RCVR_TYPE_PERIODIC,
  COCO_STD_RCVR_TYPE_WHEN_STIMULATED,
  COCO_STD_RCVR_TYPE_NOT_AVAILABLE,
  COCO_STD_RCVR_TYPE_MAX,
  COCO_STD_RCVR_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_receiver_type_t;

typedef enum {
  COCO_STD_PROTOCOL_MIN = -1,
  COCO_STD_PROTOCOL_ZWAVE,
  COCO_STD_PROTOCOL_ZIGBEE,
  COCO_STD_PROTOCOL_MAX,
  COCO_STD_PROTOCOL_UBOUND = 0x7FFFFFFF
} coco_std_protocol_id_t;

// Summary info of a resource
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  char *resourceName;
  char *manufacturer;
  char *model;
  char *firmwareVersion;
  char *metadata;
  int32_t powerSource;        // It will take values from the enum - coco_std_power_source_t
  int32_t receiverType;       // It will take values from the enum - coco_std_receiver_type_t
  int32_t explorationStatus;  // It takes values from the enum coco_std_status_code_t.
                              // The possible values are COCO_STD_STATUS_SUCCESS,
                              // COCO_STD_STATUS_PARTIAL_SUCCESS,
                              // COCO_STD_STATUS_RESOURCE_NOT_SUPPORTED,
                              // COCO_STD_STATUS_SUCCESS_INSECURE,
                              // COCO_STD_STATUS_PARTIAL_SUCCESS_INSECURE
  uint16_t createdByUserId;   // Used internally by the COCO SDKs
  time_t createdTimestamp;    // Used internally by the COCO SDKs
} coco_std_resource_summary_info_t;

// Possible capabilities of a resource
typedef enum {
  COCO_STD_CAP_MIN = -1,
  COCO_STD_CAP_ON_OFF_CONTROL,
  COCO_STD_CAP_LEVEL_CTRL,
  COCO_STD_CAP_COLOR_CTRL,
  COCO_STD_CAP_LOCK_CONTROL,
  COCO_STD_CAP_ENERGY_METERING,
  COCO_STD_CAP_MOTION_SENSING,
  COCO_STD_CAP_OCCUPANCY_SENSING,
  COCO_STD_CAP_CONTACT_SENSING,
  COCO_STD_CAP_FLUID_LEVEL_MEASUREMENT,
  COCO_STD_CAP_FIRE_SENSING,
  COCO_STD_CAP_TEMPERATURE_MEASUREMENT,
  COCO_STD_CAP_ILLUMINANCE_MEASUREMENT,
  COCO_STD_CAP_POWER_LEVEL_MEASUREMENT,
  COCO_STD_CAP_TUNNEL_CONTROL,
  COCO_STD_CAP_REL_HUMIDITY_MEASUREMENT,
  COCO_STD_CAP_KEYPRESS_SENSING,
  COCO_STD_CAP_WARNING_DEV_CONTROL,
  COCO_STD_CAP_NETWORK_CONFIGURATION,
  COCO_STD_CAP_MEDIA_STREAM,
  COCO_STD_CAP_STORAGE_CONFIG,
  COCO_STD_CAP_STORAGE_CONTROL,
  COCO_STD_CAP_MOTOR_CTRL,
  COCO_STD_CAP_IMAGE_CTRL,
  COCO_STD_CAP_SNAPSHOT,
  COCO_STD_CAP_STATIONARY_POSITION,
  COCO_STD_CAP_REAL_TIME_POSITION,
  COCO_STD_CAP_MAX,
  COCO_STD_CAP_UBOUND = 0x7FFFFFFF
} coco_std_capability_t;

// Info of a capability of a resource
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId; // It will take values from the enum - coco_std_capability_t
  char *capabilityName;
  uint32_t stdCmdArrCount;
  int32_t *stdCmdArr;
  uint16_t createdByUserId;           // Used internally by the COCO SDKs
  time_t createdTimestamp;            // Used internally by the COCO SDKs
} coco_std_resource_capability_info_t;

// Possible datatypes of an attribute value
typedef enum {
  COCO_STD_DATA_TYPE_MIN = -1,
  COCO_STD_DATA_TYPE_BOOLEAN,
  COCO_STD_DATA_TYPE_BOOLEAN_ARR,
  COCO_STD_DATA_TYPE_STRING,
  COCO_STD_DATA_TYPE_STRING_ARR,
  COCO_STD_DATA_TYPE_UINT8,
  COCO_STD_DATA_TYPE_UINT8_ARR,
  COCO_STD_DATA_TYPE_UINT16,
  COCO_STD_DATA_TYPE_UINT16_ARR,
  COCO_STD_DATA_TYPE_UINT32,
  COCO_STD_DATA_TYPE_UINT32_ARR,
  COCO_STD_DATA_TYPE_UINT64,
  COCO_STD_DATA_TYPE_UINT64_ARR,
  COCO_STD_DATA_TYPE_INT8,
  COCO_STD_DATA_TYPE_INT8_ARR,
  COCO_STD_DATA_TYPE_INT16,
  COCO_STD_DATA_TYPE_INT16_ARR,
  COCO_STD_DATA_TYPE_INT32,
  COCO_STD_DATA_TYPE_INT32_ARR,
  COCO_STD_DATA_TYPE_INT64,
  COCO_STD_DATA_TYPE_INT64_ARR,
  COCO_STD_DATA_TYPE_FLOAT,
  COCO_STD_DATA_TYPE_FLOAT_ARR,
  COCO_STD_DATA_TYPE_DOUBLE,
  COCO_STD_DATA_TYPE_DOUBLE_ARR,
  COCO_STD_DATA_TYPE_JSON_STRING,
  COCO_STD_DATA_TYPE_JSON_STRING_ARR,
  COCO_STD_DATA_TYPE_MAX,
  COCO_STD_DATA_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_data_type_t;

// Info of an attribute of a capability of a resource
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;             // It will take values from the enum - coco_std_capability_t
  char *capabilityName;
  int32_t attributeId;
  char *attribName;
  char *attribDesc;
  int32_t dataType;                 // It will take values from the enum - coco_std_data_type_t
  uint32_t dataArrayLen;            // Length of the array if dataType is an array
  void *minValue;
  void *maxValue;
  void *defaultValue;
  void *currentValue;
  uint32_t minReportingIntervalMs;
  uint32_t maxReportingIntervalMs;
  void *reportableChange;
  int32_t isRealTimeUpdate;         // If this is being sent as a result of resource updating its state,
                                    // set it as 1. Otherwise, if the old state is being sent, set it as 0
  uint16_t createdByUserId;         // Used internally by the COCO SDKs
  time_t createdTimestamp;          // Used internally by the COCO SDKs
  time_t lastUpdateTimestamp;
} coco_std_resource_attribute_info_t;

// All information about a resource capability and its attributes
typedef struct {
  coco_std_resource_capability_info_t resourceCapabilityInfo;
  uint32_t attributeArrCount;
  coco_std_resource_attribute_info_t *attributeArr;
} coco_std_resource_capability_t;

// All information about a resource, including its capabilities and attributes
typedef struct {
  coco_std_resource_summary_info_t resourceSummaryInfo;
  uint32_t capabilityArrCount;
  coco_std_resource_capability_t *capabilityArr;
} coco_std_resource_t;

// Resource command sent from Client App to OEM App
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;     // It will take values from the enum - coco_std_capability_t
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  uint32_t timeoutMs;       // Timeout in ms after which SDK will invoke the respective status
                            // callback with status as COCO_STD_STATUS_TIMEOUT and ignore status
                            // received for that particular command. timeoutMs = 0 means infinity.
  int32_t cmdId;
  void *cmdParams;
} coco_std_resource_cmd_t;

// Possible values of command status
typedef enum {
  COCO_STD_STATUS_CODE_MIN = -1,
  COCO_STD_STATUS_SUCCESS,
  COCO_STD_STATUS_INVALID,
  COCO_STD_STATUS_FAILURE,
  COCO_STD_STATUS_PARTIAL_SUCCESS,
  COCO_STD_STATUS_TIMEOUT,
  COCO_STD_STATUS_REJECTED,
  COCO_STD_STATUS_DEVICE_BUSY,
  COCO_STD_STATUS_IN_PROGRESS,
  COCO_STD_STATUS_AUTH_FAILED,
  COCO_STD_STATUS_RESOURCE_NOT_SUPPORTED,
  COCO_STD_STATUS_SUCCESS_INSECURE,
  COCO_STD_STATUS_PARTIAL_SUCCESS_INSECURE,
  COCO_STD_STATUS_CONNECTIVITY_ERROR,
  COCO_STD_STATUS_CMD_NOT_SUPPORTED,
  COCO_STD_STATUS_TOKEN_NOT_SET,
  COCO_STD_STATUS_TOKEN_REFRESH_FAILED,
  COCO_STD_STATUS_DISCOVERY_NOT_APPLICABLE,
  COCO_STD_STATUS_NETWORK_DISCONNECTED,
  COCO_STD_STATUS_CODE_MAX,
  COCO_STD_STATUS_CODE_UBOUND = 0x7FFFFFFF
} coco_std_status_code_t;

// Resource command status sent from OEM App to Client App
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;     // It will take values from the enum - coco_std_capability_t
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  int32_t status;           // It will take values from the enum - coco_std_status_code_t
} coco_std_resource_cmd_status_t;

// Sent from Device SDK to Client App to notify the firmware update start and completion
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  uint32_t packetId;
  int32_t status;         // It will take values from the enum - coco_std_status_code_t
  char *oldVersion;
  char *newVersion;
} coco_std_fw_update_notif_t;

// Advertisement of a discovered resource sent from OEM App to Client App
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  char *resourceName;
  int32_t protocolId;          //  It takes values from the enum coco_std_protocol_id_t
  uint32_t devCmdSenderNodeId; // Set it to 0xFFFFFFFF for advertising to all owners
} coco_std_resource_advertise_t;

// Possible parameters which can be sent by OEM App to Client App as message types
typedef enum {
  COCO_STD_MESSAGE_MIN = -1,
  COCO_STD_MESSAGE_PROMPT,    // Prompt to user to take offline action
  COCO_STD_MESSAGE_INFO,      // Informational messages for the user
  COCO_STD_MESSAGE_ERROR,     // Error Message
  COCO_STD_MESSAGE_WARNING,   // Warning messages
  COCO_STD_MESSAGE_CRITICAL,  // Critical or emergency condition requiring the user's attention
  COCO_STD_MESSAGE_MAX,
  COCO_STD_MESSAGE_UBOUND = 0x7FFFFFFF
} coco_std_message_type_t;

// Message sent from OEM App to be displayed on Client App when including/excluding a resource
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  uint32_t devCmdSeqNum;
  uint32_t devCmdSenderNodeId;
  char *messageTitle;
  char *messageText;
  int32_t messageType;          // It will take values from coco_std_message_type_t enum
} coco_std_message_t;

// Possible parameters which can be requested by OEM App from Client App
typedef enum {
  COCO_STD_PARAM_MIN = -1,
  COCO_STD_PARAM_USER_DEFINED,
  COCO_STD_PARAM_USERNAME,
  COCO_STD_PARAM_PASSWORD,
  COCO_STD_PARAM_PIN,
  COCO_STD_PARAM_OTP,
  COCO_STD_PARAM_INSTALL_CODE,
  COCO_STD_PARAM_CSA,
  COCO_STD_PARAM_DSK,
  COCO_STD_PARAM_RESRC_NAME,
  COCO_STD_PARAM_AVAIL_LISTEN_PORT,
  COCO_STD_PARAM_CONTENT_SEARCH,
  COCO_STD_PARAM_CONTENT_PLAYBACK,
  COCO_STD_PARAM_MAX,
  COCO_STD_PARAM_UBOUND = 0x7FFFFFFF
} coco_std_parameter_key_t;

// Parameter key-value struct used by coco_std_info_response_t and coco_std_info_request_t
typedef struct {
  int32_t key;  /* It will take values from coco_std_parameter_key_t enum */
  void *value;
} coco_std_parameter_t;

// Info request for one/more parameters sent between OEM App and Client App
typedef struct {
  char *networkId;
  uint32_t reqNodeId;
  uint32_t requestId;
  uint32_t cmdSeqNum;
  uint32_t respNodeId;
  uint32_t mandatoryInfoRequestArrCount;
  coco_std_parameter_t *mandatoryInfoRequestArr;
  uint32_t optionalInfoRequestArrCount;
  coco_std_parameter_t *optionalInfoRequestArr;
  char *messageText;
  uint32_t timeoutMs;   // Timeout in ms after which SDK will invoke the info
                        // request status callback with status as COCO_STD_STATUS_TIMEOUT
                        // and ignore info response received for that particular request.
                        // timeoutMs = 0 means infinity
} coco_std_info_request_t;

typedef struct {
  char *networkId;
  uint32_t nodeId;        // Ignored if 0
  char *resourceEUI;      // Ignored if NULL
  int32_t capabilityId;   // Ignored if COCO_STD_CAP_MIN or -1
  int32_t attributeId;    // Ignored if capabilityId is COCO_STD_CAP_MIN or COCO_STD_ATTR_*_MIN or -1
  uint16_t sceneId;       // Ignored if 0
  uint16_t ruleId;        // Ignored if 0
} coco_std_upload_triggered_uri_t;

typedef struct {
  char *networkId;
  uint32_t nodeId;        // ignored if 0
  char *resourceEUI;      // Ignored if NULL
  int32_t capabilityId;   // Ignored if COCO_STD_CAP_MIN or -1
  int32_t attributeId;    // Ignored if capabilityId is COCO_STD_CAP_MIN or COCO_STD_ATTR_*_MIN or -1
} coco_std_source_uri_t;

//For COCO_STD_PARAM_AVAIL_LISTEN_PORT:
typedef struct {
  uint8_t portCount;
  int32_t transportType;
  int32_t consecutivePort;
} coco_std_info_req_avail_listen_port_t;

typedef struct {
  uint16_t portArrCount;
  uint16_t *portArr;
} coco_std_info_resp_avail_listen_port_t;

// For COCO_STD_PARAM_PIN:
typedef struct {
  char *pin;
} coco_std_info_resp_pin_t;

// For COCO_STD_PARAM_DSK
typedef struct {
  char *dsk;
} coco_std_info_resp_dsk_t;

// For COCO_STD_PARAM_INSTALL_CODE
typedef struct {
  char *installCode;
} coco_std_info_resp_install_code_t;

//For COCO_STD_PARAM_CONTENT_SEARCH:
typedef enum {
  COCO_STD_CONTENT_SORT_BY_TYPE_MIN = -1,
  COCO_STD_CONTENT_SORT_BY_TYPE_NONE,
  COCO_STD_CONTENT_SORT_BY_TYPE_CREATED_TIME,
  COCO_STD_CONTENT_SORT_BY_TYPE_MAX,
  COCO_STD_CONTENT_SORT_BY_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_content_sort_by_type_t;

typedef enum {
  COCO_STD_CONTENT_SORT_BY_ORDER_MIN = -1,
  COCO_STD_CONTENT_SORT_BY_ORDER_NONE,
  COCO_STD_CONTENT_SORT_BY_ORDER_ASCENDING,
  COCO_STD_CONTENT_SORT_BY_ORDER_DESCENDING,
  COCO_STD_CONTENT_SORT_BY_ORDER_MAX,
  COCO_STD_CONTENT_SORT_BY_ORDER_UBOUND = 0x7FFFFFFF
} coco_std_content_sort_by_order_t;

typedef struct {
  uint8_t reqSearchCount;                 // search results count
  uint32_t offsetIndex;                   // offset for searching list
  time_t startEpochTime;                  // ignored if 0
  time_t endEpochTime;                    // ignored if 0
  int32_t contentType;                    // one of the values from coco_std_storage_content_type_t
                                          // ignored it set to COCO_STD_STORAGE_CONTENT_MIN
  int32_t uploadTriggerType;              // one of the values from coco_std_storage_upload_trigger_type_t
                                          // ignored if set to COCO_STD_STORAGE_UPLOAD_TRIGGER_MIN
  coco_std_upload_triggered_uri_t *uploadTriggeredUri;   // Ignored if NULL
  coco_std_source_uri_t *sourceUri;                      // Ignored if NULL
  int32_t sortByType;                     // one of the values from coco_std_content_sort_by_type_t
  int32_t sortByOrder;                    // one of the values from coco_std_content_sort_by_order_t
} coco_std_info_req_content_search_t;

// For COCO_STD_PARAM_CONTENT_PLAYBACK:
typedef struct {
  uint64_t contentId;
  int32_t streamProtocolType;      //  It takes values from the enum coco_std_stream_protocol_type_t
} coco_std_info_req_content_playback_t;

typedef enum {
  COCO_STD_STREAM_PROTOCOL_TYPE_MIN = -1,
  COCO_STD_STREAM_PROTOCOL_TYPE_DASH,
  COCO_STD_STREAM_PROTOCOL_TYPE_HLS,
  COCO_STD_STREAM_PROTOCOL_TYPE_HDS,
  COCO_STD_STREAM_PROTOCOL_TYPE_SMOOTH,
  COCO_STD_STREAM_PROTOCOL_TYPE_MAX,
  COCO_STD_STREAM_PROTOCOL_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_stream_protocol_type_t;

typedef enum {
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_MIN = -1,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_NONE,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_TIMEOUT,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_NOT_FOUND,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_PROT_NOT_SUPPORTED,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_INTERNAL,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_MAX,
  COCO_STD_CONTENT_PLAYBACK_REQ_ERROR_UBOUND = 0x7FFFFFFF
} coco_std_content_playback_req_error_t;

typedef struct {
  int32_t streamProtocolType;      //  It takes values from the enum coco_std_stream_protocol_type_t
  char *playbackUrl;
  int32_t contentPlaybackReqError; //  It takes values from the enum coco_std_content_playback_req_error_t
} coco_std_info_resp_content_playback_t;

typedef enum {
  COCO_STD_STORAGE_CONTENT_MIN = -1,
  COCO_STD_STORAGE_CONTENT_STREAM,
  COCO_STD_STORAGE_CONTENT_ATTRIBUTE,
  COCO_STD_STORAGE_CONTENT_FILE,
  COCO_STD_STORAGE_CONTENT_MAX,
  COCO_STD_STORAGE_CONTENT_UBOUND = 0x7FFFFFFF
} coco_std_storage_content_type_t;

typedef enum {
  COCO_STD_STORAGE_UPLOAD_TRIGGER_MIN = -1,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_USER,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_ATTRB,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_SCENE,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_RULE,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_MAX,
  COCO_STD_STORAGE_UPLOAD_TRIGGER_UBOUND = 0x7FFFFFFF
} coco_std_storage_upload_trigger_type_t;

typedef struct {
  uint64_t contentId;
  coco_std_source_uri_t sourceUri;
  int32_t contentType;
  int32_t uploadTriggerType;
  coco_std_upload_triggered_uri_t uploadTriggeredUri;
  uint32_t size;
  char *staticLink;
  char *userMetaData;
  uint64_t createdTimestamp;
  uint32_t contentDuration;
} coco_std_storage_content_metadata_t;

typedef struct {
  uint64_t totalSearchCount;
  uint8_t reqSearchCount;
  coco_std_storage_content_metadata_t *contentMetaDataArr;
} coco_std_info_resp_content_search_t;

// For COCO_STD_PARAM_USER_DEFINED:
typedef struct {
  char *request;
  uint16_t requestLen;
} coco_std_info_req_user_defined_t;

typedef struct {
  char *response;
  uint16_t responseLen;
} coco_std_info_resp_user_defined_t;

// Info response for the requested parameters sent from Client App to OEM App
typedef struct {
  char *networkId;
  uint32_t reqNodeId;
  uint32_t requestId;
  uint32_t cmdSeqNum;
  uint32_t infoResponseArrCount;
  coco_std_parameter_t *infoResponseArr;
} coco_std_info_response_t;

// Sent when a resource is removed from a Device
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *resourceEui;
  uint32_t packetId;      // Used internally by the COCO SDKs
} coco_std_removed_resource_t;

// Possible device commands
typedef enum {
  COCO_STD_DEVICE_CMD_MIN = -1,
  COCO_STD_DEVICE_CMD_DISCOVER_RES,
  COCO_STD_DEVICE_CMD_ADD_RES,
  COCO_STD_DEVICE_CMD_REM_RES,
  COCO_STD_DEVICE_CMD_REBOOT,
  COCO_STD_DEVICE_CMD_UPD_RES_NAME,
  COCO_STD_DEVICE_CMD_UPD_RES_META,
  COCO_STD_DEVICE_CMD_FORCE_REM_RES,
  COCO_STD_DEVICE_CMD_CONF_WIFI,
  COCO_STD_DEVICE_CMD_MAX,
  COCO_STD_DEVICE_CMD_UBOUND = 0x7FFFFFFF
} coco_std_device_cmd_id_t;

// Device command to update the name of a resource
typedef struct {
  char *resourceEui;
  char *resourceName;
} coco_std_device_cmd_upd_res_name_t;

// Device command to update the metadata of a resource
typedef struct {
  char *resourceEui;
  char *metadata;
} coco_std_device_cmd_upd_res_meta_t;

// Device command to discover resource to a device
typedef struct {
  int32_t protocolId;       //  It takes values from the enum coco_std_protocol_id_t
} coco_std_device_cmd_discover_res_t;

// Device command to add a resource to a device
typedef struct {
  char *resourceEui;
  int32_t protocolId;       //  It takes values from the enum coco_std_protocol_id_t
  char *resourceMetadata;
  uint32_t paramArrCount;
  coco_std_parameter_t *paramArr;
} coco_std_device_cmd_add_res_t;

// Device command to remove a resource from a device
typedef struct {
  char *resourceEui;
  uint32_t paramArrCount;
  coco_std_parameter_t *paramArr;
} coco_std_device_cmd_rem_res_t;

// Device command to force remove a resource from a device
typedef struct {
  char *resourceEui;
} coco_std_device_cmd_force_rem_res_t;

// Device command to force remove a resource from a device
typedef struct {
  char *ssid;
  char *password;
} coco_std_device_cmd_conf_wifi_t;

// Device command sent from Client App SDK to Device SDK
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  uint32_t timeoutMs;       // Timeout in ms after which SDK will invoke the respective status
                            // callback with status as COCO_STD_STATUS_TIMEOUT and ignore status
                            // received for that particular command. timeoutMs = 0 means infinity.
  char *accessToken;        // To be used by the SDKs internally
  int32_t cmdId;            // It will take values from the enum - coco_std_device_cmd_id_t
  void *cmdParams;
} coco_std_device_cmd_t;

// Device command status sent from Device SDK to Client App SDK
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  int32_t status;           // It will take values from the enum - coco_std_status_code_t
  char **impactedResourceArr; /* As of now, it is only being used for commands
                                 COCO_STD_DEVICE_CMD_DISCOVER_RES and COCO_STD_DEVICE_CMD_ADD_RES.
                                 It contains the EUIs of the resources which got added as a result
                                 of these two device commands. */
  uint32_t impactedResourceArrCnt; /* As of now, it is only being used for commands
                                      COCO_STD_DEVICE_CMD_DISCOVER_RES and COCO_STD_DEVICE_CMD_ADD_RES.
                                      It contains the number of elements present in impactedResourceArr. */
} coco_std_device_cmd_status_t;

// Possible roles of a user in a cocoNet
typedef enum {
  COCO_STD_USER_ROLE_MIN = -1,
  COCO_STD_USER_ROLE_OWNER,
  COCO_STD_USER_ROLE_ADMIN,
  COCO_STD_USER_ROLE_GUEST,
  COCO_STD_USER_ROLE_MAX,
  COCO_STD_USER_ROLE_UBOUND = 0x7FFFFFFF
} coco_std_user_role_type_t;

// Possible access type for a user in a cocoNet
typedef enum {
  COCO_STD_ACCESS_TYPE_MIN = -1,
  COCO_STD_ACCESS_TYPE_LOCAL,
  COCO_STD_ACCESS_TYPE_REMOTE,
  COCO_STD_ACCESS_TYPE_MAX,
  COCO_STD_ACCESS_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_access_type_t;

// Resource of a zone
typedef struct {
  uint32_t deviceNodeId;
  char *resourceEui;
  char *resourceName;
  char *metadata;
  uint16_t createdByUserId; // Used internally by the COCO SDKs
  time_t createdTimestamp;  // Used internally by the COCO SDKs
} coco_std_zone_resource_t;

// All information about a Zone and its resources
typedef struct {
  char *networkId;
  uint16_t zoneId;
  char *zoneName;
  uint16_t resourceArrCount;
  coco_std_zone_resource_t *resourceArr;
  uint32_t packetId;                      // Used internally by the COCO SDKs
  uint16_t createdByUserId;               // Used internally by the COCO SDKs
  time_t createdTimestamp;                // Used internally by the COCO SDKs
} coco_std_zone_entity_t;

// Resource action of a scene and rule
typedef struct {
  uint16_t resrcActionId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;     // It will take values from the enum - coco_std_capability_t
  int32_t cmdId;
  void *cmdParams;
  uint16_t createdByUserId; // Used internally by the COCO SDKs
  time_t createdTimestamp;  // Used internally by the COCO SDKs
} coco_std_resrc_action_t;

// Metadata of a scene
typedef struct {
  char *sceneMetadata;
  uint32_t subclusterId;
} coco_std_scene_metadata_t;

// All information about a Scene and its resource actions
typedef struct {
  char *networkId;
  uint16_t sceneId;
  char *sceneName;
  char *metadata;
  uint16_t resrcActionArrCount;
  coco_std_resrc_action_t *resrcActionArr;
  uint16_t sceneMetadataArrCount;                 // Used internally by the COCO SDKs
  coco_std_scene_metadata_t *sceneMetadataArr;    // Used internally by the COCO SDKs
  uint32_t packetId;                              // Used internally by the COCO SDKs
  uint16_t createdByUserId;                       // Used internally by the COCO SDKs
  time_t createdTimestamp;                        // Used internally by the COCO SDKs
} coco_std_scene_entity_t;

// Possible values of operator type
typedef enum {
  COCO_STD_OPERATOR_MIN = -1,
  COCO_STD_OPERATOR_EQUAL_TO,
  COCO_STD_OPERATOR_NOT_EQUAL_TO,
  COCO_STD_OPERATOR_GRTR_THAN,
  COCO_STD_OPERATOR_GRTR_THAN_EQUAL_TO,
  COCO_STD_OPERATOR_LESS_THAN,
  COCO_STD_OPERATOR_LESS_THAN_EQUAL_TO,
  COCO_STD_OPERATOR_MAX,
  COCO_STD_OPERATOR_UBOUND = 0x7FFFFFFF
} coco_std_operator_t;

// Resource condition of a rule
typedef struct {
  uint16_t ruleId;              // Used internally by the COCO SDK
  uint16_t ruleResCondId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;         // It will take values from the enum - coco_std_capability_t
  int32_t attributeId;
  int32_t operatorId;           // It will take values from the enum - coco_std_operator_t
  int32_t valueDataTypeId;      // It will take values from the enum - coco_std_data_type_t
  void *currentValue;           // Used internally by the COCO SDKs
  void *ruleValue;
  uint32_t condDurationMs;
  time_t attrLastUpdatedTime;   // Used internally by the COCO SDKs
  uint16_t createdByUserId;     // Used internally by the COCO SDKs
  time_t createdTimestamp;      // Used internally by the COCO SDKs
} coco_std_rule_resrc_condn_t;

// Possible schedule condition types
typedef enum {
  COCO_STD_RULE_SCH_TYPE_MIN = -1,
  COCO_STD_SCH_ONETIME,
  COCO_STD_SCH_DAILY,
  COCO_STD_SCH_WEEKLY,
  COCO_STD_SCH_MONTHLY,
  COCO_STD_SCH_YEARLY,
  COCO_STD_RULE_SCH_TYPE_MAX,
  COCO_STD_RULE_SCH_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_rule_sched_type_t;

// Schedule condition of a rule
typedef struct {
  uint16_t ruleId;              // Used internally by the COCO SDK
  uint16_t ruleSchCondId;
  int32_t ruleSchedTypeId;      // It will take values from the enum - coco_std_rule_sched_type_t
  uint8_t ruleCondMonth;
  uint8_t ruleCondDayOfMonth;
  uint8_t ruleCondWeek;
  uint8_t ruleCondDayOfWeek;
  char *ruleCondDate;
  char *ruleCondTime;
  char *ruleExpiryTime;
  time_t lastSatisfiedTime;     // Used internally by the COCO SDKs
  uint16_t createdByUserId;     // Used internally by the COCO SDKs
  time_t createdTimestamp;      // Used internally by the COCO SDKs
} coco_std_rule_sched_condn_t;

// Scene action of a rule
typedef struct {
  uint16_t sceneId;
  uint16_t createdByUserId; // Used internally by the COCO SDKs
  time_t createdTimestamp;  // Used internally by the COCO SDKs
} coco_std_rule_scene_action_t;

// Rule info
typedef struct {
  char *networkId;
  uint16_t ruleId;
  char *ruleName;
  uint16_t resrcCondnArrCount;
  coco_std_rule_resrc_condn_t *resrcCondnArr;
  uint16_t schedCondnArrCount;
  coco_std_rule_sched_condn_t *schedCondnArr;
  uint16_t resrcActionArrCount;
  coco_std_resrc_action_t *resrcActionArr;
  uint16_t sceneActionArrCount;
  coco_std_rule_scene_action_t *sceneActionArr;
  uint32_t packetId;                            // Used internally by the COCO SDKs
  uint16_t createdByUserId;                     // Used internally by the COCO SDKs
  time_t createdTimestamp;                      // Used internally by the COCO SDKs
} coco_std_rule_entity_t;

// Status of resource action of a rule
typedef struct {
  uint16_t ruleResActionId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;           // It will take values from the enum - coco_std_capability_t
  int32_t cmdId;
  void *cmdParams;
  int32_t status;                 // It will take values from the enum - coco_std_status_code_t
} coco_std_rule_res_act_status_t;

// Status of resource action of a scene belonging to a rule
typedef struct {
  uint16_t sceneResActionId;
  uint32_t deviceNodeId;
  char *resourceEui;
  int32_t capabilityId;             // It will take values from the enum - coco_std_capability_t
  int32_t cmdId;
  void *cmdParams;
  int32_t status;                   // It will take values from the enum - coco_std_status_code_t
} coco_std_scene_res_act_status_t;

// Status of scene action of a rule
typedef struct {
  uint16_t ruleSceneActionId;
  uint16_t sceneResActStatusArrCount;
  coco_std_scene_res_act_status_t *sceneResActStatusArr;
} coco_std_rule_scene_act_status_t;

// Status of rule execution
typedef struct {
  char *networkId;
  uint16_t ruleId;
  char *ruleName;
  uint16_t resrcCondnArrCount;
  coco_std_rule_resrc_condn_t *resrcCondnArr;
  uint16_t schedCondnArrCount;
  coco_std_rule_sched_condn_t *schedCondnArr;
  uint16_t resActStatusArrCount;
  coco_std_rule_res_act_status_t *resActStatusArr;
  uint16_t sceneActStatusArrCount;
  coco_std_rule_scene_act_status_t *sceneActStatusArr;
  uint32_t packetId;                                    // Used internally by the COCO SDKs
} coco_std_rule_status_t;

// Info of a device
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  char *devicePsn;
  char *deviceName;
  char *productName;
  char *make;             // Manufacture Name
  char *model;
  char *firmwareVersion;
  char **resourceEuiArr;
  uint32_t resourceEuiArrCnt;
  int32_t *protocolIdArr;
  uint32_t protocolIdArrCnt;
  int32_t powerSource;    // It will take values from the enum - coco_std_power_source_t
  int32_t receiverType;   // It will take values from the enum - coco_std_receiver_type_t
  int32_t isExtendable;
} coco_std_device_info_t;

// Error codes
typedef enum {
  COCO_STD_ERRNO_MIN = -1,
  COCO_STD_NO_ERROR = 0,
  COCO_STD_INVAL_ARGS,
  COCO_STD_NO_PAYLOAD,
  COCO_STD_OUT_OF_BOUNDS,
  COCO_STD_INVAL_JSON,
  COCO_STD_ERRNO_MAX,
  COCO_STD_ERRNO_UBOUND = 0x7FFFFFFF
} coco_std_errno_t;

// An enum for status of the tunnel
typedef enum {
  COCO_STD_TUNNEL_STATUS_MIN = -1,
  COCO_STD_TUNNEL_OPENING,
  COCO_STD_TUNNEL_OPENED,
  COCO_STD_TUNNEL_REOPENED,
  COCO_STD_TUNNEL_OPEN_FAILED,
  COCO_STD_TUNNEL_CLOSED,
  COCO_STD_TUNNEL_CLOSE_FAILED,
  COCO_STD_TUNNEL_STATUS_MAX,
  COCO_STD_TUNNEL_STATUS_UBOUND = 0x7FFFFFFF
} coco_std_tunnel_status_t;

// Possible coconet commands
typedef enum {
  COCO_STD_COCONET_CMD_MIN = -1,
  COCO_STD_COCONET_CMD_SET_ZONE_INFO,
  COCO_STD_COCONET_CMD_REM_ZONE,
  COCO_STD_COCONET_CMD_ADD_ZONE_RES,
  COCO_STD_COCONET_CMD_REM_ZONE_RES,
  COCO_STD_COCONET_CMD_MOVE_ZONE_RES,
  COCO_STD_COCONET_CMD_SET_SCENE_INFO,
  COCO_STD_COCONET_CMD_REM_SCENE,
  COCO_STD_COCONET_CMD_ADD_SCENE_RES_ACT,
  COCO_STD_COCONET_CMD_UPDATE_SCENE_RES_ACT,
  COCO_STD_COCONET_CMD_REM_SCENE_RES_ACT,
  COCO_STD_COCONET_CMD_SET_RULE_INFO,
  COCO_STD_COCONET_CMD_REM_RULE,
  COCO_STD_COCONET_CMD_ADD_RULE_RES_COND,
  COCO_STD_COCONET_CMD_UPDATE_RULE_RES_COND,
  COCO_STD_COCONET_CMD_REM_RULE_RES_COND,
  COCO_STD_COCONET_CMD_ADD_RULE_SCH_COND,
  COCO_STD_COCONET_CMD_UPDATE_RULE_SCH_COND,
  COCO_STD_COCONET_CMD_REM_RULE_SCH_COND,
  COCO_STD_COCONET_CMD_ADD_RULE_RES_ACT,
  COCO_STD_COCONET_CMD_UPDATE_RULE_RES_ACT,
  COCO_STD_COCONET_CMD_REM_RULE_RES_ACT,
  COCO_STD_COCONET_CMD_ADD_RULE_SCENE_ACT,
  COCO_STD_COCONET_CMD_REM_RULE_SCENE_ACT,
  COCO_STD_COCONET_CMD_SET_SCENE_METADATA,
  COCO_STD_COCONET_CMD_SAVE_SCENE_SETTINGS,
  COCO_STD_COCONET_CMD_SAVE_RULE_SETTINGS,
  COCO_STD_COCONET_CMD_MAX,
  COCO_STD_COCONET_CMD_UBOUND = 0x7FFFFFFF
} coco_std_coconet_cmd_id_t;

// COCONet management command sent from Client App SDK to Device SDK
typedef struct {
  char *networkId;
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  uint32_t timeoutMs;           // Timeout in ms after which SDK will invoke the respective status
                                // callback with status as COCO_STD_STATUS_TIMEOUT and ignore status
                                // received for that particular command. timeoutMs = 0 means infinity.
  int32_t cmdId;                // It will take values from the enum - coco_std_coconet_cmd_id_t
  void *cmdParams;
} coco_std_coconet_mgmt_cmd_t;

// Network command to create a new zone or set name for an existing zone
typedef struct {
  uint16_t zoneId;
  char *zoneName;
} coco_std_cmd_set_zone_t;

// Network command to add a resource to a zone
typedef struct {
  uint16_t zoneId;
  uint16_t resourceArrCount;
  coco_std_zone_resource_t *resourceArr;
} coco_std_cmd_add_zone_res_t;

// Network command to create a new scene or set name for an existing scene
typedef struct {
  uint16_t sceneId;
  char *sceneName;
} coco_std_cmd_set_scene_t;

// Network command to add a resource action to a scene
typedef struct {
  uint16_t sceneId;
  uint16_t resrcActionArrCount;
  coco_std_resrc_action_t *resrcActionArr;
} coco_std_cmd_set_scene_res_act_t;

// COCONet command to save scene settings in network
typedef coco_std_cmd_set_scene_res_act_t coco_std_cmd_save_scene_settings_t;

typedef enum {
  COCO_STD_CMD_ERR_CODE_MIN = -1,
  COCO_STD_CMD_ERR_BAD_REQUEST = 40000,
  COCO_STD_CMD_ERR_MISSING_PARAMS = 40001,
  COCO_STD_CMD_ERR_INVALID_PARAMS = 40002,
  COCO_STD_CMD_ERR_INVALID_RANGE = 40003,
  COCO_STD_CMD_ERR_DUP_DATA = 40004,
  COCO_STD_CMD_ERR_USR_NOT_EXISTS = 40006,
  COCO_STD_CMD_ERR_GW_NOT_IN_NW = 40007,
  COCO_STD_CMD_ERR_NAME_RECCURING = 40009,
  COCO_STD_CMD_ERR_USR_EXISTS = 40010,
  COCO_STD_CMD_ERR_DUP_PRODUCT = 40011,
  COCO_STD_CMD_ERR_AUTH_REQUIRED = 40101,
  COCO_STD_CMD_ERR_SESSION_EXPIRED = 40102,
  COCO_STD_CMD_ERR_INVALID_CREDENTIALS = 40103,
  COCO_STD_CMD_ERR_ACCESS_RESTRICTED = 40301,
  COCO_STD_CMD_ERR_GW_BUSY = 40302,
  COCO_STD_CMD_ERR_JOIN_PROGRESS = 40303,
  COCO_STD_CMD_ERR_GW_NOT_PROVISION = 40304,
  COCO_STD_CMD_ERR_GW_ALREADY_OWNED = 40305,
  COCO_STD_CMD_ERR_ALREADY_PROGRESS = 40306,
  COCO_STD_CMD_ERR_DISABLE_APPLICATION = 40307,
  COCO_STD_CMD_ERR_NOT_FOUND = 40401,
  COCO_STD_CMD_ERR_FILE_NOT_FOUND = 40402,
  COCO_STD_CMD_ERR_RES_NOT_FOUND = 40403,
  COCO_STD_CMD_ERR_INPUT_RES_NOT_FOUND = 40404,
  COCO_STD_CMD_ERR_NW_UNALLOCATED = 40406,
  COCO_STD_CMD_ERR_INTERNAL_SERVER = 50001,
  COCO_STD_CMD_ERR_PAYMENT_FAILED = 50002,
  COCO_STD_CMD_ERR_TX_FAILED = 50050,               // Transmission of command failed
  COCO_STD_CMD_ERR_DATABASE_ERROR = 50301,
  COCO_STD_CMD_ERR_SERVER_ERROR = 50302,
  COCO_STD_CMD_ERR_HTTP_TIMEOUT = 50450,           // The request to the server timed out
  COCO_STD_CMD_ERR_CMD_TIMEOUT = 50451,            // The command could not be completed in the
                                                   // time specified while sending the command
  COCO_STD_CMD_ERR_CODE_MAX,
  COCO_STD_CMD_ERR_CODE_UBOUND = 0x7FFFFFFF
} coco_std_cmd_error_code_t;

typedef struct {
  int32_t code;           // It takes value from the enum coco_std_cmd_error_code_t
  char *message;          // Description of the error. It might not be set for all error codes.
  char *fieldName;        // It specifies which field in the command had error.
                          // It might not be set for all error codes.
} coco_std_cmd_error_t;

// COCONet management command status sent from Network Management Node to Client App SDK
typedef struct {
  char *networkId;
  uint32_t cmdSenderNodeId;
  uint32_t cmdSeqNum;
  int32_t statusCode;       // It will take values from the enum - coco_std_status_code_t
  coco_std_cmd_error_t *error;
} coco_std_coconet_mgmt_cmd_status_t;

// COCONet command to create a new rule or set name for an existing rule
typedef struct {
  uint16_t ruleId;
  char *ruleName;
} coco_std_cmd_set_rule_t;

// COCONet command to add a resource condition to a rule
typedef struct {
  uint16_t ruleId;
  uint16_t resrcCondnArrCount;
  coco_std_rule_resrc_condn_t *resrcCondnArr;
} coco_std_cmd_set_rule_res_cond_t;

// COCONet command to add a schedule condition to a rule
typedef struct {
  uint16_t ruleId;
  coco_std_rule_sched_condn_t *schedCondnArr;
  uint16_t schedCondnArrCount;
} coco_std_cmd_set_rule_sch_cond_t;

// COCONet command to add a resource action to a rule
typedef struct {
  uint16_t ruleId;
  uint16_t resrcActionArrCount;
  coco_std_resrc_action_t *resrcActionArr;
} coco_std_cmd_set_rule_res_act_t;

// COCONet command to add a scene action to a rule
typedef struct {
  uint16_t ruleId;
  uint16_t sceneActionArrCount;
  coco_std_rule_scene_action_t *sceneActionArr;
} coco_std_cmd_add_rule_scene_act_t;

// COCONet command to save rule settings in network
typedef coco_std_rule_entity_t coco_std_cmd_save_rule_settings_t;

// COCONet command to remove a zone from the COCONet
typedef struct {
  uint16_t *zoneIdArr;
  uint16_t zoneIdArrCnt;
} coco_std_cmd_rem_zone_t;

// COCONet command to remove a resource from a zone
typedef struct {
  uint16_t zoneId;
  uint16_t resourceArrCount;
  coco_std_zone_resource_t *resourceArr;
} coco_std_cmd_rem_zone_res_t;

// COCONet command to remove a scene from the network
typedef struct {
  uint16_t *sceneIdArr;
  uint16_t sceneIdArrCnt;
} coco_std_cmd_rem_scene_t;

// COCONet command to remove a resource action from a scene
typedef struct {
  uint16_t sceneId;
  uint16_t *resrcActionArr;
  uint16_t resrcActionArrCount;
} coco_std_cmd_rem_scene_res_act_t;

// COCONet command to remove a rule from the network
typedef struct {
  uint16_t *ruleIdArr;
  uint16_t ruleIdArrCount;
} coco_std_cmd_rem_rule_t;

// COCONet command to remove a resource condition from a rule
typedef struct {
  uint16_t ruleId;
  uint16_t *ruleResCondIdArr;
  uint16_t ruleResCondIdArrCount;
} coco_std_cmd_rem_rule_res_cond_t;

// COCONet command to remove a schedule condition from a rule
typedef struct {
  uint16_t ruleId;
  uint16_t *ruleSchCondIdArr;
  uint16_t ruleSchCondIdArrCount;
} coco_std_cmd_rem_rule_sch_cond_t;

// COCONet command to remove a resource action from a rule
typedef struct {
  uint16_t ruleId;
  uint16_t *resrcActionArr;
  uint16_t resrcActionArrCount;
} coco_std_cmd_rem_rule_res_act_t;

// COCONet command to remove a scene action from a rule
typedef struct {
  uint16_t ruleId;
  uint16_t *sceneIdArr;
  uint16_t sceneIdArrCount;
} coco_std_cmd_rem_rule_scene_act_t;

// COCONet command to move a resource from one zone to another.
typedef struct {
  uint16_t oldZoneId;
  uint16_t newZoneId;
  uint16_t resourceArrCount;
  coco_std_zone_resource_t *resourceArr;
} coco_std_cmd_move_zone_res_t;

// Sent when a zone is deleted
typedef struct {
  uint16_t zoneId;
  uint32_t packetId;
  char *networkId;
} coco_std_zone_deleted_t;

// Sent when a scene is deleted
typedef struct {
  uint16_t sceneId;
  uint32_t packetId;
  char *networkId;
} coco_std_scene_deleted_t;

// Sent when a rule is deleted
typedef struct {
  uint16_t ruleId;
  uint32_t packetId;
  char *networkId;
} coco_std_rule_deleted_t;

// Network command to set metadata for an existing scene
typedef struct {
  uint16_t sceneId;
  char *sceneMetadata;
} coco_std_cmd_set_scene_metadata_t;

// Sent when a resource is added to a Device
typedef struct {
  char *networkId;
  uint32_t deviceNodeId;
  uint32_t resourceArrCount;
  coco_std_resource_t *resourceArr;
} coco_std_added_resource_t;

typedef enum {
  COCO_STD_NODE_TYPE_MIN = -1,
  COCO_STD_NODE_TYPE_NETWORK,
  COCO_STD_NODE_TYPE_DEVICE,
  COCO_STD_NODE_TYPE_CLIENT,
  COCO_STD_NODE_TYPE_MAX,
  COCO_STD_NODE_TYPE_UBOUND = 0x7FFFFFFF
} coco_std_node_type_t;

// Media frame type
typedef enum {
  COCO_STD_MEDIA_FRAME_TYPE_MIN = -1,
  COCO_STD_MEDIA_FRAME_TYPE_NONE,
  COCO_STD_MEDIA_FRAME_TYPE_KEY,
  COCO_STD_MEDIA_FRAME_TYPE_MAX,
  COCO_STD_MEDIA_FRAME_UNBOUND = 0x7FFFFFFF
} coco_std_media_frame_type_t;

 #pragma pack(1)
typedef struct {
  uint32_t frameIndex;
  coco_std_media_frame_type_t frameType;  // Key frame or none
  uint64_t frameDuration;                 // Fixed frame rate producer in hundreds of nano seconds
  uint64_t framePTS;                      // Frame presentation timestamp in hundreds of nano seconds
  uint32_t frameSize;
} coco_std_media_frame_packed_pkt_t;
#pragma pack()

typedef struct {
  uint32_t frameIndex;
  coco_std_media_frame_type_t frameType;  // Key frame or none
  uint64_t frameDuration;                 // Fixed frame rate producer in hundreds of nano seconds
  uint64_t framePTS;                      // Frame presentation timestamp in hundreds of nano seconds
  uint32_t frameSize;
  char *frameData;
} coco_std_media_frame_pkt_t;

/*************************************************************************************
 *                          GLOBAL VARIABLES                                         *
 *************************************************************************************/
/********************************************//**
 * @brief The thread-local Error Number returned by the last cocostandard API call.
 *
 * cocoStdErrno is updated by each cocostandard API with the resulting error code from the
 * function. This is not reset before each function call, so its value should be specifically
 * reset by the caller if needed for comparison purposes.
 * This errno is threadLocal in order to avoid multiple threads altering the value for
 * another thread.
 ***********************************************/
extern int32_t threadLocal cocoStdErrno;

/*************************************************************************************
 *                          PUBLIC FUNCTIONS                                         *
 *************************************************************************************/
/********************************************//**
 * @brief   Gets the error description for an error code
 * @details This function returns an error description string for a cocoStdErrno value
 *          set by a cocostandard API. The string is allocated by this API and does not need
 *          to be de-allocated by the caller.
 * @param   errorNum: cocoStdErrno value set by a cocostandard API. It takes value from
 *                    coco_std_errno_t enum
 * @return  const char *: a string describing the error
 ***********************************************/
const char *coco_std_strerror(int32_t errorNum);

/********************************************//**
 * @brief   Print error description to standard error (stderr) output stream
 * @details This function prints to the standard error (stderr) output stream the error description
 *          for the current value of the cocoStdErrno variable set by cocostandard API's.
 *          The description is prefixed by the label string passed as an argument,
 *          a colon(:) and a space
 * @param   errorLabel: Label to be printed before the error description
 * @return  void
 ***********************************************/
void coco_std_perror(const char *errorLabel);

/********************************************//**
 * @brief   API to clean up the allocated memory
 * @details This function will deallocate the memory based on the structType
 * @param   structType: Type of struct to be deallocated
 * @param   numRecords: Number of records to deallocate
 * @param   structPtr : Pointer to memory allocated variable. It takes values from
 *                      coco_std_struct_type_t enum
 * @return  void
 ***********************************************/
void coco_std_free_data(int32_t structType, uint32_t numRecords, void *structPtr);

 /********************************************//**
 * @brief   Packs media frame packet
 * @details This function will return a packed media frame packet, user need to
 *          call coco_std_free_pack_media_frame() to free data
 * @param   mediaFrame     : Media frame from which a frame packet is created
 * @param   len            : packed media frame data length to be allocated
 * @return  void *         : Returns packed media frame packet on success
 *                           NULL in case of error
 ***********************************************/
void *coco_std_pack_media_frame(coco_std_media_frame_pkt_t *mediaFrame, size_t *len);

 /********************************************//**
 * @brief   Unpacks media frame packet
 * @details This function will return a unpacked media frame packet, user need to
 *          call coco_std_free_unpack_media_frame() to free data
 * @param   data                          : Media frame packet
 * @return  coco_std_media_frame_pkt_t *  : Return unpacked media frame struct in case of success
 *                                          NULL in case of error
 ***********************************************/
coco_std_media_frame_pkt_t *coco_std_unpack_media_frame(void *data);

 /********************************************//**
 * @brief   Free media frame struct
 * @details This function frees the unpacked media frame and it's frameData
 * @param   mediaFrame                    : Unpacked media frame packet
 * @return  int                           : Return 0 in case of success
 *                                          -1 in case of error
 ***********************************************/
int coco_std_free_unpack_media_frame(coco_std_media_frame_pkt_t *mediaFrame);

 /********************************************//**
 * @brief   Free media frame packet
 * @details This function frees the packed media frame and it's frameData
 * @param   mediaFrame                    : Media frame packet
 * @return  int                           : Return 0 in case of success
 *                                          -1 in case of error
 ***********************************************/
int coco_std_free_pack_media_frame(void *packet);

#endif // COCO_STD_API_H_INCLUDED
