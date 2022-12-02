

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

    color: Constants.backgroundColor

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 320
        height: 480
        color: "#001f1f1f"
        border.width: 0
        z: 2

        Label {
            id: label
            x: 124
            y: 87
            color: "#ffffff"
            text: qsTr("Login")
            font.bold: true
            font.pointSize: 20
        }

        TextField {
            id: textField
            x: 74
            y: 156
            width: 173
            height: 46
            placeholderText: qsTr("Username")
        }

        TextField {
            id: textField1
            x: 74
            y: 208
            width: 173
            height: 46
            placeholderText: qsTr("Password")
        }

        Button {
            id: button
            x: 79
            y: 276
            width: 162
            height: 48
            text: qsTr("Continue")
            font.letterSpacing: 0
            z: 0
            font.capitalization: Font.Capitalize
            font.bold: true
            hoverEnabled: true
            checkable: false
            flat: true
            highlighted: true
            down: false
            checked: false
        }
    }

    Rectangle {
        id: rectangle2
        x: 320
        y: 0
        width: 320
        height: 480
        color: "#00666666"
        border.width: 0
        z: 2

        Text {
            id: text1
            x: 41
            y: 148
            width: 239
            height: 84
            color: "#ffffff"
            text: qsTr("We are here to revolutionize the world, one shape at a time. Critics say, \"The DEMO is out of this world!\"")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap
            font.bold: true
        }

        Button {
            id: button1
            x: 108
            y: 250
            width: 105
            height: 48
            text: qsTr("Contact Us")
            font.bold: true
            font.capitalization: Font.Capitalize
            down: false
            highlighted: true
            flat: false
        }
    }

    Rectangle {
        id: rectangle4
        x: 0
        y: 0
        width: 320
        height: 480
        color: "#1f1f1f"
        border.width: 0
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#434343"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
            orientation: Gradient.Vertical
        }
        z: 0
    }

    Rectangle {
        id: rectangle5
        x: 320
        y: 0
        width: 320
        height: 480
        color: "#6f4b75"
        border.width: 0
        z: 0
    }
    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:9}D{i:13}
}
##^##*/

