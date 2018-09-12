/* OpenSprinkler Unified (AVR/RPI/BBB/LINUX) Firmware
 * Copyright (C) 2015 by Ray Wang (ray@opensprinkler.com)
 *
 * Utility functions header file
 * Feb 2015 @ OpenSprinkler.com
 *
 * This file is part of the OpenSprinkler library
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <http://www.gnu.org/licenses/>. 
 */

#ifndef _UTILS_H
#define _UTILS_H

#if defined(ARDUINO)

#else // headers for RPI/BBB
  #include <stdio.h>
  #include <limits.h>
  #include <sys/time.h>

#endif
#include "defines.h"

// File reading/writing functions
void write_to_file(const char *fname, const char *data, int size, int pos=0, bool trunc=true);
void read_from_file(const char *fname, char *data, int maxsize=TMP_BUFFER_SIZE, int pos=0);
void remove_file(const char *fname);

void file_read_block (const char *fname, void *dst, int pos, int len);
void file_write_block(const char *fname, void *src, int pos, int len);
byte file_read_byte (const char *fname, int pos);
void file_write_byte(const char *fname, int pos, byte v);  

// misc. string and time converstion functions
void strncpy_P0(char* dest, const char* src, int n);
ulong water_time_resolve(uint16_t v);
byte water_time_encode_signed(int16_t i);
int16_t water_time_decode_signed(byte i);

#if defined(ARDUINO)

#else // Arduino compatible functions for RPI/BBB
  char* get_runtime_path();
  char* get_filename_fullpath(const char *filename);
  void delay(ulong ms);
  void delayMicroseconds(ulong us);
  void delayMicrosecondsHard(ulong us);
  ulong millis();
  ulong micros();
  void initialiseEpoch();
#if defined(OSPI)
  unsigned int detect_rpi_rev();
#endif
#endif  // NVM functions

#endif // _UTILS_H
