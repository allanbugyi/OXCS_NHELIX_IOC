Oxford Cryo Systems N-Helix Cryostream IOC.
==========================================
Campinas, 09/14/18 - LNLS/CNPEM
Version 1.0
Tested with Moxa NPort device (RS232 to Ethernet port conversor)

Author: Allan S. B. Bugyi (allan.bugyi@lnls.br)

Running the IOC
===============
To establish communication with N-Helix you first need to run the following command: 'caput OXCS_NHELIX:DISABLE 0'
This will also enable sending commands to N-Helix. To disable communication and sending commands just change value '0' in above command to '1'.

Variables of interest and commands
==================================

**PVs**
Variable name     PV name
TEMP		- OXCS_NHELIX:TEMP
GAS SET POINT	- OXCS_NHELIX:SETPOINT
SHIELD TEMP	- OXCS_NHELIX:EVAPTEMP
NOZZLE TEMP	- OXCS_NHELIX:SUCTTEMP
GAS HEAT	- OXCS_NHELIX:GASHEAT
SHIELD HEAT	- OXCS_NHELIX:EVAPHEAT
NOZZLE HEAT	- OXCS_NHELIX:SUCTHEAT
ALARM		- OXCS_NHELIX:ALARM.VALA
GAS FLOW	- OXCS_NHELIX:GASFLOW
LINE PRESSURE	- OXCS_NHELIX:BACKPRESS
DETECTED GAS TYPE - OXCS_NHELIX:DETGASTYPE
SELECTED GAS TYPE - OXCS_NHELIX:SELGASTYPE
RUN MODE	- OXCS_NHELIX:RUNMODE
PHASE (just for run mode = 1 StartUpFail) - OXCS_NHELIX:PHASE

**Commands**
Restart
	caput OXCS_NHELIX:RESTART 1
Ramp
	First specify Ramp Rate and the target temperature for the ramp:
		caput OXCS_NHELIX:RRATE <1-360 (K/hour)>
		caput OXCS_NHELIX:RTEMP <20-320 (K)>
		caput OXCS_NHELIX:RAMP 1
Plat
	First specify the duration time of the plat:
		caput OXCS_NHELIX:PTIME <1-1440(24hrs) (min)>
		caput OXCS_NHELIX:PLAT 1
		
Hold
		caput OXCS_NHELIX:HOLD 1
Cool
	First specify the target temperature to cool:
		caput OXCS_NHELIX:CTEMP <2000-32000 (cK)>
		caput OXCS_NHELIX:COOL 1
End
	caput OXCS_NHELIX:END 1
Purge
	caput OXCS_NHELIX:PURGE 1
Pause
	caput OXCS_NHELIX:PAUSE 1
Resume
	caput OXCS_NHELIX:RESUME 1
Stop
	caput OXCS_NHELIX:STOP 1
ForceHe
	caput OXCS_NHELIX:FORCEHE 1

Development
===========
Command list for 700 and 800 series (RS232): <http://oxcryo.com/serialcomms/700series/nh_command.html>

The docs for Ethernet interface communication is under 'docs/' dir.

The protocol file under 'proto/' dir, communicates with N-Helix in a serial fashion (RS232). It was used a conversor to Ethernet port, for network publishing purposes. Ethernet interface communication not implemented but feasible.




