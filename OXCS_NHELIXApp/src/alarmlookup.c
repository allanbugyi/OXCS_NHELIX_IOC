#include <stdio.h>
#include <string.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <genSubRecord.h>
#include <epicsExport.h>
#include <alarm.h>
#include <recGbl.h>

typedef long (*processMethod)(genSubRecord *precord);

static long alarmlookupProcess(genSubRecord *p)
{
	/* lookup a string from an int value */
	int lookupval = *(int *)p->a;
	char* strArray[] = {"No Alarm",
						"Stop Button Pressed",
						"Stop Command Received",
						"End Phase Done",
						"Purge Phase Done",
						"Temp Warning",
						"Pressure Warning",
						"Check Vacuum",
						"Self-check fail",
						"Flow rate fail",
						"Temp control error",
						"Gas type error",
						"Temp reading error",
						"Suct temp error",
						"Sensor fail",
						"Brownout",
						"Sink overheat",
						"PSU overheat",
						"Power loss",
						"Coldhead too cold",
						"Coldhead time out",
						"Cryodrive not found",
						"Cryodrive error",
						"No nitrogen",
						"No helium",
						"Vacuum gauge fail",
						"Vacuum reading error",
						"RS232 error",
						"Coldhead temp warning",
						"Coldhead temp error",
						"Do not open cryostat",
						"Do not open cryostat",
						"Unplug Xtal sensor",
						"Cryostat open",
						"Cryostat open timeout",
						"High temp warning",
						"High temp error",
						"Cryodrive T sensor fault",
						"Cryodrive P sensor fault",
						"Cryodrive low T trip",
						"Cryodrive high T trip",
						"Cryodrive low P trip",
						"Cryodrive high T warning",
						"Cryodrive low P warning",
						"Connect gas supply",
						"Autofill fault",
						"Autofill about to fill",
						"Autofill filling",
						"Colar temp error",
						"Coldhead error",
						"Turbo flow",
						"He selected",
						"Cryodrive not ready",
						"Regen required",
						"Regen complete",
						"Connect vaccum",
						"Disconnect vaccum"};

	
	if (lookupval < sizeof(strArray)/sizeof(strArray[0]))
	{
		strcpy(p->vala,strArray[lookupval]);
		if (((lookupval>0)&(lookupval<3)) || (lookupval==46) || (lookupval==50) || (lookupval==51) || (lookupval==54)) recGblSetSevr(p,epicsAlarmState,epicsSevMinor);
		else if(lookupval<56) recGblSetSevr(p,epicsAlarmState,epicsSevMajor);
		//else recGblSetSevr(p,epicsAlarmState,epicsSevNone);
	}
	else
	{
		strcpy(p->vala,"Illegal Alarm");
	}
    return(0);
}

/* Register these symbols for use by IOC code: */
epicsRegisterFunction(alarmlookupProcess);
