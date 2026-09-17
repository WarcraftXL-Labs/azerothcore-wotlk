/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HOTFIXESDATABASE_H
#define _HOTFIXESDATABASE_H

#include "MySQLConnection.h"

enum HotfixesDatabaseStatements : uint32
{
    MAX_HOTFIXESDATABASE_STATEMENTS
};

class AC_DATABASE_API HotfixesDatabaseConnection : public MySQLConnection
{
public:
    typedef HotfixesDatabaseStatements Statements;

    // Constructors for sync and async connections
    HotfixesDatabaseConnection(MySQLConnectionInfo& connInfo);
    HotfixesDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo);
    ~HotfixesDatabaseConnection() override;

    // Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif
