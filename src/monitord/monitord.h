/* Copyright (C) 2015-2019, Wazuh Inc.
 * Copyright (C) 2009 Trend Micro Inc.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

#ifndef MONITORD_H
#define MONITORD_H

#ifndef ARGV0
#define ARGV0 "ossec-monitord"
#endif

#include "config/reports-config.h"

#define MAX_DAY_WAIT 600
#define MONITORD_MSG_HEADER "1:" ARGV0 ":"
#define AG_DISCON_MSG MONITORD_MSG_HEADER OS_AG_DISCON

/* Prototypes */
void Monitord(void) __attribute__((noreturn));
void manage_files(int cday, int cmon, int cyear);
void generate_reports(int cday, int cmon, int cyear, const struct tm *p);
void monitor_agents(void);
void OS_CompressLog(const char *logfile);
char *w_rotate_log(char *old_file, int compress, int maxage, int new_day, int rotate_json, int daily_rotations,
                   int last_counter, rotation_list *list_log, rotation_list *list_json);
int delete_old_agent(const char *agent_id);
time_t calc_next_rotation(time_t tm, struct tm *rot, const char units, int interval);

/* Parse read config into JSON format */
cJSON *getMonitorOptions(void);
cJSON *getReportsOptions(void);
cJSON *getMonitorLogging(void);
size_t moncom_dispatch(char * command, char ** output);
size_t moncom_getconfig(const char * section, char ** output);
void * moncom_main(__attribute__((unused)) void * arg);

/* Global variables */
extern monitor_config mond;

#endif /* MONITORD_H */
