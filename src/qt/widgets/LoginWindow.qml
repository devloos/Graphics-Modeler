/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Studio Components.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 6.4
import QtQuick.Window 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3
import My.Shapes
import My.Singletons

Window {
    width: loginUI.width
    height: loginUI.height

    maximumWidth: loginUI.width
    maximumHeight: loginUI.height
    minimumWidth: loginUI.width
    minimumHeight: loginUI.height

    visible: true
    title: "Graphics Modeler"

    LoginUI {
        id: loginUI
        login_btn.onClicked: CppInterface.callMe()
    }
}

