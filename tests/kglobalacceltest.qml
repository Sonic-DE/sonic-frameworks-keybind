/*
    This file is part of the KDE libraries

    SPDX-FileCopyrightText: 2022 Aleix Pol Gonzalez <aleixpol@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import org.kde.kquickcontrols 2.0
import org.kde.globalaccel 1.0

ApplicationWindow
{
    visible: true

    Rectangle {
        color: action.active ? "green" : "yellow"
        anchors.fill: parent

        GlobalAction {
            id: action
            text: "Hola"
            onTriggered: console.log("woah")
            objectName: "org.kde.globalaccel.test.globalacceltest"
            shortcut: sequenceItem.keySequence
        }

        KeySequenceItem
        {
            id: sequenceItem
            modifierlessAllowed: true
            keySequence: "Meta+X"
        }
    }
}
