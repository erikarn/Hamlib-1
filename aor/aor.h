/*
 *  Hamlib AOR backend - main header
 *  Copyright (c) 2000-2005 by Stephane Fillod
 *
 *	$Id: aor.h,v 1.23 2006-11-02 15:19:58 aa6e Exp $
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Library General Public License for more details.
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef _AOR_H
#define _AOR_H 1

#include <hamlib/rig.h>

#define BACKEND_VER "0.4"


int format8k_mode(RIG *rig, char *buf, rmode_t mode, pbwidth_t width);
int parse8k_aor_mode(RIG *rig, char aormode, char aorwidth, rmode_t *mode, pbwidth_t *width);

struct aor_priv_caps {
	int (*format_mode)(RIG *rig, char *buf, rmode_t mode, pbwidth_t width);
	int (*parse_aor_mode)(RIG *rig, char aormode, char aorwidth, rmode_t *mode, pbwidth_t *width);
	char bank_base1;
	char bank_base2;
};

int aor_close(RIG *rig);

int aor_set_freq(RIG *rig, vfo_t vfo, freq_t freq);
int aor_get_freq(RIG *rig, vfo_t vfo, freq_t *freq);
int aor_set_mode(RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width);
int aor_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width);
int aor_set_vfo(RIG *rig, vfo_t vfo);
int aor_get_vfo(RIG *rig, vfo_t *vfo);

int aor_set_level(RIG *rig, vfo_t vfo, setting_t level, value_t val);
int aor_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val);
int aor_get_dcd(RIG *rig, vfo_t vfo, dcd_t *dcd);

int aor_set_ts(RIG *rig, vfo_t vfo, shortfreq_t ts);
int aor_set_powerstat(RIG *rig, powerstat_t status);
int aor_vfo_op(RIG *rig, vfo_t vfo, vfo_op_t op);
const char *aor_get_info(RIG *rig);

int aor_set_mem(RIG *rig, vfo_t vfo, int ch);
int aor_get_mem(RIG *rig, vfo_t vfo, int *ch);
int aor_set_bank(RIG *rig, vfo_t vfo, int bank);

int aor_get_channel(RIG *rig, channel_t *chan);
int aor_set_channel(RIG *rig, const channel_t *chan);
int aor_get_chan_all_cb (RIG * rig, chan_cb_t chan_cb, rig_ptr_t);

extern const struct rig_caps ar2700_caps;
extern const struct rig_caps ar8200_caps;
extern const struct rig_caps ar8000_caps;
extern const struct rig_caps ar8600_caps;
extern const struct rig_caps ar5000_caps;
extern const struct rig_caps ar3000a_caps;
extern const struct rig_caps ar7030_caps;
extern const struct rig_caps ar3030_caps;
extern const struct rig_caps ar5000a_caps;

#endif /* _AOR_H */
