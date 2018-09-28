#!../../bin/linux-x86_64/OXCS_NHELIX

## You may have to change OXCS700 to something else
## everywhere it appears in this file

< envPaths

# Configure StreamDevice paths
epicsEnvSet("STREAM_PROTOCOL_PATH", "../../proto")

## Register all support components
dbLoadDatabase("../../dbd/OXCS_NHELIX.dbd",0,0)
OXCS_NHELIX_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("eth0", "10.0.9.51:4001", 0,0,0)
#asynSetTraceMask("eth0", -1, 0x9)
#asynSetTraceIOMask("eth0", -1, 0x2)

## Load record instances
dbLoadRecords("../../db/OXCS_NHELIX.db","P=, Q=OXCS_NHELIX, PORT=eth0")

iocInit()

## Start any sequence programs
#seq sncOXCS700,"user=root"
