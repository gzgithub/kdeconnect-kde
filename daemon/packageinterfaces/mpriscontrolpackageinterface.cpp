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

#include "mpriscontrolpackageinterface.h"

#include <QDebug>
#include <QDBusConnection>
#include <QDBusInterface>
#include <qdbusconnectioninterface.h>
#include <QDBusReply>
#include <QDBusMessage>

MprisControlPackageInterface::MprisControlPackageInterface()
{
    //TODO: Emit info read form mpris to the phone
}

bool MprisControlPackageInterface::receivePackage (const Device& device, const NetworkPackage& np)
{
    Q_UNUSED(device);

    if (np.type() != PACKAGE_TYPE_MPRIS) return false;

    QString action = np.get<QString>("action");

    QStringList interfaces = QDBusConnection::sessionBus().interface()->registeredServiceNames().value();
    Q_FOREACH (const QString& iface, interfaces) {
        if (iface.startsWith("org.mpris.MediaPlayer2")) {
            QDBusInterface mprisInterface(iface, "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player");
            mprisInterface.asyncCall(action);
        }
    }

    return true;

}