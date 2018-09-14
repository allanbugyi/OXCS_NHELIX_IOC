TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = OXCS_NHELIX
# OXCS_NHELIX.dbd will be created and installed
DBD += OXCS_NHELIX.dbd

# OXCS700.dbd will be made up from these files:
OXCS_NHELIX_DBD += base.dbd
OXCS_NHELIX_DBD += stream.dbd
OXCS_NHELIX_DBD += asyn.dbd
OXCS_NHELIX_DBD += drvAsynIPPort.dbd
OXCS_NHELIX_DBD += calcSupport.dbd
OXCS_NHELIX_DBD += genSubRecord.dbd
OXCS_NHELIX_DBD += alarmlookup.dbd

# Include dbd files from all support applications:
#OXCS_NHELIX_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#OXCS_NHELIX_LIBS += xxx

OXCS_NHELIX_LIBS += asyn stream 
OXCS_NHELIX_LIBS += calc genSub

# OXCS700_registerRecordDeviceDriver.cpp derives from OXCS700.dbd
OXCS_NHELIX_SRCS += alarmlookup.c
OXCS_NHELIX_SRCS += OXCS_NHELIX_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
OXCS_NHELIX_SRCS_DEFAULT += OXCSNHELIXMain.cpp
OXCS_NHELIX_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#OXCS_NHELIX_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
OXCS_NHELIX_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

