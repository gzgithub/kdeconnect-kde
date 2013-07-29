/**
 * Copyright 2013 Albert Vaca <albertvaka@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PACKAGEINTERFACE_H
#define PACKAGEINTERFACE_H

#include <QObject>

#include "networkpackage.h"
#include "device.h"

class PackageInterface
    : public QObject
{
    Q_OBJECT

public:
    PackageInterface(QObject* parent = 0);
    virtual ~PackageInterface() { }

public Q_SLOTS:
    //Returns true if it has handled the package in some way
    virtual bool receivePackage(const Device& device, const NetworkPackage& np) = 0;

Q_SIGNALS:
    void sendPackage(const NetworkPackage& np);
};

#endif