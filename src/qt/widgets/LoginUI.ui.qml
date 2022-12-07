

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.4
import QtQuick.Controls 6.4
//import GraphicsModelerUI
import QtQuick.Controls.Material 2.3

Rectangle {
    id: rectangle
    width: 640
    height: 480

    color: "#c2c2c2"

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    property alias button1 : coolButton
    Button
    {
        id: coolButton
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:9}D{i:13}
}
##^##*/

