/*
	I2CServer - SRCP Server fuer den I2C Bus.
	Aufbau wie SRCPSession empfaengt die Signale vom I2C Bus
	und leitet sie an die lokalen Geraete weiter, fragt Sensoren
	ab, etc.

	Im Sketch als WireServer ansprechbar.

	Beispiel fuer eine Implementation sie SRCPGASlave oder
	SRCPGLSave.

	Copyright (c) 2010 Marcel Bernet.  All right reserved.

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef I2CSERVER_H_
#define I2CSERVER_H_

#include <Arduino.h>
#include "../srcp/SRCPCommand.h"

namespace i2c
{

class I2CServer
{
private:
	int addr;
	srcp::command_t cmd;
	void dispatch(uint8_t* args, int size );
	int dispatchTx();
	static void slaveRxEvent(uint8_t* rxBuf, int size);
	static void slaveTxEvent();
public:
	void begin( int id, int version, int addr = -1 );
	void run();
	int getMyAddr() { return( addr ); }
};

}
extern i2c::I2CServer WireServer;

#endif /* I2CSERVER_H_ */
