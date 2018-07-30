#!../../bin/linux-x86_64/OXCS700

## You may have to change OXCS700 to something else
## everywhere it appears in this file

< envPaths

# Configure StreamDevice paths
epicsEnvSet("STREAM_PROTOCOL_PATH", "../../data")

## Register all support components
dbLoadDatabase("../../dbd/OXCS700.dbd",0,0)
OXCS700_registerRecordDeviceDriver(pdbbase)

drvAsynSerialPortConfigure("OXCS_NHELIX","tty0",0,0,0)

## Load record instances
dbLoadRecords("../../db/OXcommon700.db","P=OXCS, Q=_NHELIX, PORT=tty0")

iocInit()

## Start any sequence programs
#seq sncOXCS700,"user=root"
