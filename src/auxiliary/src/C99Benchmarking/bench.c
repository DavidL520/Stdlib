#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdarg.h>
#include <string.h>
#include <time.h>

#include "sac.h"

#define SECONDS 0
#define MILLIS 1
#define MICROS 2
#define NANOS 3

static const char * unitName[] = {"s", "ms", "us", "ns"};

struct bench {                                                   
  int                num;
  char *             name;
  int                timeUnit;
  double             startTime;
  double             stopTime;
};

void benchStart( struct bench *interval, double time) 
{                                                            
  interval->startTime = time;
}                                                                        
                                                                         
void benchEnd( struct bench* interval, double time)                                   
{                                                            
  interval->stopTime = time;
}                         
                                               
void benchThis( void)
{                                                                        
  /* noop*/
}                                                                        

double benchRes( struct bench* interval)
{
  return( interval->stopTime - interval->startTime);
}

char* benchName( struct bench* interval)
{
  char* newName = SAC_MALLOC( strlen( interval->name) + 1);
  strncpy( newName, interval->name, strlen( interval->name) + 1);
  return( newName);
}

int benchNum( struct bench* interval)
{
  return( interval->num);
}

char* benchUnitName( struct bench* interval)
{
  char* unit_name = SAC_MALLOC( strlen( unitName[interval->timeUnit]) + 1);
  strncpy( unit_name, unitName[interval->timeUnit], strlen( unitName[interval->timeUnit]) + 1);
  return( unit_name);
}

int benchUnit( struct bench* interval)
{
  return( interval->timeUnit);
}

void benchCreate( struct bench** interval)                                                
{                                                                        
  /* benchGetInterval actually creates the data structure */
}     

struct bench* benchGetInterval_si(char * name, int num)
{                                                                        
  struct bench *interval;
  char* newName;
  interval = (struct bench*)SAC_MALLOC( sizeof( struct bench));
  interval->num = num;                                    
  newName = SAC_MALLOC( strlen( name) + 1);
  strncpy( newName, name, strlen( name) + 1);
  interval->name = newName;
  interval->timeUnit = SECONDS;
  return( interval);
}                                                                        
 
struct bench* benchGetInterval_i( int num)               
{                                                                        
  struct bench *interval;
  interval = benchGetInterval_si("\0", num);
  return( interval);
}                                                                        

struct bench* benchGetInterval_s( char *name) 
{                                                                        
  struct bench *interval;
  interval = benchGetInterval_si(name, -1);
  return( interval);
}                                                                        

struct bench* benchGetInterval_siu(char * name, int num, int timeunit)
{                                                                        
  struct bench *interval;
  char* newName;
  interval = (struct bench*)SAC_MALLOC( sizeof( struct bench));
  interval->num = num;                                    
  newName = SAC_MALLOC( strlen( name) + 1);
  strncpy( newName, name, strlen( name) + 1);
  interval->name = newName;
  interval->timeUnit = timeunit;
  return( interval);
}                                                                        

struct bench* benchGetInterval_iu( int num, int timeunit)               
{                                                                        
  struct bench *interval;
  interval = benchGetInterval_siu("\0", num, timeunit);
  return( interval);
}                                                                        

struct bench* benchGetInterval_su( char *name, int timeunit) 
{                                                                        
  struct bench *interval;
  interval = benchGetInterval_siu(name, -1, timeunit);
  return( interval);
}                                                                        
                                                                         
void benchDestroyInterval( struct bench *interval)                        
{                                                                        
  free(interval->name);
  free(interval);                                                        
}                            
                                            
