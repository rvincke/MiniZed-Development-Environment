/*----------------------------------------------------------------------------
**      _____
**     *     *
**    *____   *____
**   * *===*   *==*
**  *___*===*___**  AVNET
**       *======*
**        *====*
**----------------------------------------------------------------------------
**
** This design is the property of Avnet.  Publication of this
** design is not authorized without written consent from Avnet.
**
** Disclaimer:
**    Avnet, Inc. makes no warranty for the use of this code or design.
**    This code is provided  "As Is". Avnet, Inc assumes no responsibility for
**    any errors, which may appear in this code, nor does it make a commitment
**    to update the information contained herein. Avnet, Inc specifically
**    disclaims any implied warranties of fitness for a particular purpose.
**
**                     Copyright(c) 2018 Avnet, Inc.
**                             All rights reserved.
**
**----------------------------------------------------------------------------
**
** Create Date:         Feb 25, 2018
** File Name:           mz_axi_stream.h
**
** Tool versions:       Vivado 2017.4
**
** Description:         MiniZed Header File for prototypes and parameters
**
** Revision:            Feb 25, 2018: 1.00 Initial version
**                      Jul 09, 2018: 1.10 Updated to use non-blocking HW
**                                         function calls
**
**----------------------------------------------------------------------------*/

#ifndef MZ_HEADER_H_
#define MZ_HEADER_H_

/*
** CONSTANTS
*/
#define BUFFER_DEPTH    4096
#define DM_DEPTH        1026
#define NUM_BUFFERS     5

/*
** Types
*/
typedef struct
{
  int total_errors;
  int buff_errors[NUM_BUFFERS];
} stats_t;

/*
** FUNCTION PROTOTYPES
*/

void mz_axi_stream();

#pragma SDS data sys_port( p_stream:axis_data_fifo_0_M_AXIS )
#pragma SDS data copy( p_buffer[0:p_samples] )
#pragma SDS data copy( p_stream[0:p_samples] )
#pragma SDS data access_pattern( p_buffer:SEQUENTIAL )
#pragma SDS data access_pattern( p_stream:SEQUENTIAL )
#pragma SDS data mem_attribute( p_buffer:PHYSICAL_CONTIGUOUS )
#pragma SDS data mem_attribute( p_stream:PHYSICAL_CONTIGUOUS )

void read_stream( uint32_t *p_stream,
                  uint32_t *p_buffer,
                  uint32_t  p_samples);

#endif /* MZ_HEADER_H_ */
