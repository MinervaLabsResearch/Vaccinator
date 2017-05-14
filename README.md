# Vaccinator
Vaccinating against WannaCry ransomware: a free tool by Minerva's research team.
Updated version, thanks for [Didier Stevens](https://twitter.com/DidierStevens) and [@gN3mes1s](https://twitter.com/gN3mes1s) for sharing the mutex they found with the community.
 
## Synopsis
This tool demonstrates how to vaccinate against the WannaCry ransomware by creating infection markers on the protected machine, preventing the ransomware from running and encrypting your machine.
Endpoints running this script will be protected against known variants of the above ransomware.
 
### WannaCry
High-profile ransomware attack, infecting over 230,000 computers in 150 countries, leveraging a Windows SMB vulnerability (MS17-010).
For more information visit the following blog post: https://minerva-labs.com/post/immune-yourself-from-wannacry-ransomware-with-minervas-free-vaccinator

## Installation
In real life scenarios WannaCry typically runs on session 0, by exploiting MS17-010, and looking for the infection markers within this session.
This means that the tool must run in session 0 so it will create the infection markers there.

### Installation Procedure for Forensics Environment/Malware Lab
* Simply run the vaccinator excecutable in the same session you want to run the malware sample.

### Installation Procedure for Production Environment
The following will install the tool as a service, thus vaccinating session 0.
* Download and extract Windows Server 2003 Resource Kit Tools (suitable for newer OS versions as well)
* Use InstSrv.exe & SrvAny.exe in order to create a service that will execute the vaccination utility (More information can be found here: https://support.microsoft.com/en-us/help/137890/how-to-create-a-user-defined-service), for example:
`"c:\program files (x86)\windows resource kits\tools\instsrv.exe" MinervaVaccinationUtility "C:\Program Files (x86)\Windows Resource Kits\Tools\srvany.exe"`
* Run regedit.exe to set the new service parameters:
	* Navigate to HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\MinervaVaccinationUtility
	* Create a subkey called Parameters
		* Add a REG_SZ value with the following attributes:
			* Name = Application
			* Value = c:\path\to\Vaccinator.exe
* Use services.msc to verify that the start mode of the service is automatic and then to start it

## Download the Tool
You may download the compiled tool from:

https://s3-eu-west-1.amazonaws.com/minervaresearchpublic/Tools/Vaccinator.exe