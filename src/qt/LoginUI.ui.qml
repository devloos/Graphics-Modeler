import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    property alias login_btn : login_btn
    property alias contact_btn : contact_btn
    property alias username : username
    property alias password : password

    width: window._LOGIN_WIDTH
    height: window._LOGIN_HEIGHT

    color: "#c2c2c2"

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        id: login_form
        x: 0
        y: 0
        z: 2
        width: 320
        height: 480
        color: "#001f1f1f"
        border.width: 0

        Label {
            id: login_title
            x: 124
            y: 87
            color: "#ffffff"
            text: qsTr("Login")
            font.bold: true
            font.pointSize: 20
        }

        TextField {
            id: username
            x: 74
            y: 156
            width: 173
            height: 46
            placeholderText: qsTr("Username")
        }

        TextField {
            id: password
            x: 74
            y: 208
            width: 173
            height: 46
            placeholderText: qsTr("Password")
        }

        Button {
            id: login_btn
            x: 79
            y: 276
            z: 0
            width: 162
            height: 48
            text: qsTr("Continue")
            font.letterSpacing: 0
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
        id: contact_info
        x: 320
        y: 0
        z: 2
        width: 320
        height: 480
        color: "#00666666"
        border.width: 0

        Text {
            id: contact_introduction
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
            id: contact_btn
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
        id: login_background
        x: 0
        y: 0
        z: 0
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
    }

    Rectangle {
        id: contact_background
        x: 320
        y: 0
        z: 0
        width: 320
        height: 480
        color: "#6f4b75"
        border.width: 0

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#000000"
            }

            GradientStop {
                position: 1
                color: "#6f4b75"
            }
            orientation: Gradient.Vertical
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:9}D{i:13}
}
##^##*/
