Oxford Cryo Systems N-Helix Cryostream IOC.
==========================================
Campinas, 09/14/18 - LNLS/CNPEM
Version 1.0
Tested with Moxa NPort device (RS232 to Ethernet port conversor)

Author: Allan S. B. Bugyi (allan.bugyi@lnls.br)

Running the IOC
===============
To establish communication with N-Helix you first need to run the following command: 'caput CATERETE:OXCS_NHELIX:DISABLE 0'
This will also enable sending commands to N-Helix. To disable communication and sending commands just change value '0' in above command to '1'.

Variables of interest and commands
==================================

**PVs**
Variable name     PV name
TEMP		- CATERETE:OXCS_NHELIX:TEMP
GAS SET POINT	- CATERETE:OXCS_NHELIX:SETPOINT
SHIELD TEMP	- CATERETE:OXCS_NHELIX:EVAPTEMP
NOZZLE TEMP	- CATERETE:OXCS_NHELIX:SUCTTEMP
GAS HEAT	- CATERETE:OXCS_NHELIX:GASHEAT
SHIELD HEAT	- CATERETE:OXCS_NHELIX:EVAPHEAT
NOZZLE HEAT	- CATERETE:OXCS_NHELIX:SUCTHEAT
ALARM		- CATERETE:OXCS_NHELIX:ALARM.VALA
GAS FLOW	- CATERETE:OXCS_NHELIX:GASFLOW
LINE PRESSURE	- CATERETE:OXCS_NHELIX:BACKPRESS
DETECTED GAS TYPE - CATERETE:OXCS_NHELIX:DETGASTYPE
SELECTED GAS TYPE - CATERETE:OXCS_NHELIX:SELGASTYPE
RUN MODE	- CATERETE:OXCS_NHELIX:RUNMODE
PHASE (just for run mode = 1 StartUpFail) - CATERETE:OXCS_NHELIX:PHASE

**Commands**
Restart
	caput OXCS_NHELIX:RESTART 1
Ramp
	First specify Ramp Rate and the target temperature for the ramp:
		caput CATERETE:OXCS_NHELIX:RRATE <1-360 (K/hour)>
		caput CATERETE:OXCS_NHELIX:RTEMP <20-320 (K)>
		caput CATERETE:OXCS_NHELIX:RAMP 1
Plat
	First specify the duration time of the plat:
		caput CATERETE:OXCS_NHELIX:PTIME <1-1440(24hrs) (min)>
		caput CATERETE:OXCS_NHELIX:PLAT 1
		
Hold
		caput CATERETE:OXCS_NHELIX:HOLD 1
Cool
	First specify the target temperature to cool:
		caput CATERETE:OXCS_NHELIX:CTEMP <2000-32000 (cK)>
		caput CATERETE:OXCS_NHELIX:COOL 1
End
	caput CATERETE:OXCS_NHELIX:END 1
Purge
	caput CATERETE:OXCS_NHELIX:PURGE 1
Pause
	caput CATERETE:OXCS_NHELIX:PAUSE 1
Resume
	caput CATERETE:OXCS_NHELIX:RESUME 1
Stop
	caput CATERETE:OXCS_NHELIX:STOP 1
ForceHe
	caput CATERETE:OXCS_NHELIX:FORCEHE 1

Development
===========
Command list for 700 and 800 series (RS232): <http://oxcryo.com/serialcomms/700series/nh_command.html>

The docs for Ethernet interface communication is under 'docs/' dir.

The protocol file under 'proto/' dir, communicates with N-Helix in a serial fashion (RS232). It was used a conversor to Ethernet port, for network publishing purposes. Ethernet interface communication not implemented but feasible.




