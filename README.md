      __  __       _ _           
     |  \/  | __ _(_) | ___ _ __ 
     | |\/| |/ _` | | |/ _ \ '__|
     | |  | | (_| | | |  __/ |   
     |_|  |_|\__,_|_|_|\___|_|   


       
-----
ABOUT	
-----

  MuaMi is a lightweight email client written in Qt5 and C++.
  It currently supports the protocols IMAPS and SMTPS.
  To use it, please go to the section INSTALL below.
  
-------
AUTHORS	
-------

· Marc Melkonian <marc.melkonian@etud.univ-paris8.fr>
  (IED n°13410425)

· Antoine De Blieck

---------
ChangeLog
---------

  - 27 July 18: v0.0.1
      . First version
      . Completed integration between GUI and network

  - 05 October 15: 
      . Start of connecting GUI with network 

-------
INSTALL
-------

Prerequisites:
- openssl library 
- openssl library 

Installation and running:
1. First run qmake
2. Then make
3. Launch mailer

  2. Enter your account information and credentials in
     the configuration file "muarc" and move it to your $HOME folder.

  3. Run 'make && muami' to compile and run the program.

-------------
CONFIGURATION
-------------

Muami uses the XDG Base Directory Specification for the path of the
configuration files.

Every e-mail account settings must be stored on seperate files with
no naming convention required.

The syntax of the options are as following:
<field> : <value>

Field can be:
in_server    :  incoming e-mail server url
in_port      :  incoming e-mail server port
smtp_server  :  outgoing (SMTP) e-mail server url  
smtp_port    :  outgoing (SMTP) e-mail server port  
from         :  name of the sender  
email        :  e-mail address
user         :  username to log into the servers  
pass         :  password of user  
protocol     :  incoming e-mails protocol (IMAP)


-----------------
COPYING / LICENSE
-----------------

  GPL3

-----------------
TROUBLESHOOTING
-----------------

1/ I get a SIGSERV error just after being logged into my mail server.

*> Try to increase the timeout value in SSL_manager.cpp. Due to a too low
   timeout, commands sent and responses from the server are likely to be mixed
   up.

----------
KNOWN BUGS	
----------

  - Segfaults can occur on server connection sometimes
 
  - Client should send a NOOP command before server timeout (this value is
    in the server greeting)
 
