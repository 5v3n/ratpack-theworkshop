#ifndef __CONFIG_H__
#define __CONFIG_H__

// ratpack server
char* HOST         = "YOUR-HOSTNAME";
char* USERAGENT    = "ratpack-workshop/alpha";
char* RESOURCE     = "/status.json";
//io settings
byte buttonPin            = 2;    // button pin 
byte ledPin               = 9;   // led pin
//misc
long unsigned int pause   = 1000;

#endif
