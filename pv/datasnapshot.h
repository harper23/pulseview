/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_DATASNAPSHOT_H
#define PULSEVIEW_PV_DATASNAPSHOT_H

extern "C" {
#include <libsigrok/libsigrok.h>
}

namespace pv {

class DataSnapshot
{
public:
	DataSnapshot(int unit_size);

	virtual ~DataSnapshot();

	uint64_t get_sample_count();

protected:
	void append_data(void *data, uint64_t samples);

protected:
	void *_data;
	uint64_t _sample_count;
	int _unit_size;
};

} // namespace pv

#endif // PULSEVIEW_PV_DATASNAPSHOT_H
