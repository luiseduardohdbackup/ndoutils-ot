/************************************************************************
 *
 * UTILS.H - NDO utilities header file
 *
 * Copyright (c) 2009-2012 Nagios Core Development Team and Community Contributors
 * Copyright (c) 2005-2008 Ethan Galstad
 *
 * Last Modified: 09-27-2012
 *
 ************************************************************************/

#ifndef _NDO_UTILS_H
#define _NDO_UTILS_H

/* my_free has been freed from bondage as a function */
#ifdef BUILD_NAGIOS_2X
#define my_free(ptr) { if(ptr) { free(ptr); ptr = NULL; } }
#else
#define my_free(ptr) do { if(ptr) { free(ptr); ptr = NULL; } } while(0)
#endif


typedef struct ndo_dbuf_struct{
	char *buf;
	unsigned long used_size;
	unsigned long allocated_size;
	unsigned long chunk_size;
        }ndo_dbuf;


int ndo_dbuf_init(ndo_dbuf *,int);
int ndo_dbuf_free(ndo_dbuf *);
int ndo_dbuf_strcat(ndo_dbuf *,char *);

int my_rename(char *,char *);

void ndomod_strip(char *);

#endif
