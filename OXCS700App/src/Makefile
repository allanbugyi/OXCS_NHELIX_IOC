TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = OXCS700
# OXCS700.dbd will be created and installed
DBD += OXCS700.dbd

# OXCS700.dbd will be made up from these files:
OXCS700_DBD += base.dbd
OXCS700_DBD += stream.dbd
OXCS700_DBD += asyn.dbd
OXCS700_DBD += drvAsynSerialPort.dbd
OXCS700_DBD += calcSupport.dbd
OXCS700_DBD += genSubRecord.dbd
OXCS700_DBD += alarmlookup.dbd

# Include dbd files from all support applications:
#OXCS700_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#OXCS700_LIBS += xxx

OXCS700_LIBS += asyn stream 
OXCS700_LIBS += calc genSub

# OXCS700_registerRecordDeviceDriver.cpp derives from OXCS700.dbd
OXCS700_SRCS += alarmlookup.c
OXCS700_SRCS += OXCS700_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
OXCS700_SRCS_DEFAULT += OXCS700Main.cpp
OXCS700_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#OXCS700_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
OXCS700_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

