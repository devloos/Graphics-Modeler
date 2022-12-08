import QtQuick 6.4
import QtQuick.Window 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3
import My.Shapes
import My.Singletons

Window {
    readonly property int _LOGIN_WIDTH: 640
    readonly property int _LOGIN_HEIGHT: 480
    readonly property int _MAIN_WIDTH: 1440
    readonly property int _MAIN_HEIGHT: 720

    id: window

    width: _LOGIN_WIDTH
    height: _LOGIN_HEIGHT
    maximumWidth: _LOGIN_WIDTH
    maximumHeight: _LOGIN_HEIGHT
    minimumWidth: _LOGIN_WIDTH
    minimumHeight: _LOGIN_HEIGHT

    x: Screen.width / 2 - width / 2
    y: Screen.height / 2 - height / 2

    visible: true
    title: "Graphics Modeler"

    LoginUI {
        id: login_ui
        visible: true
        login_btn.onClicked: {
            if (CppInterface.loginConnection(username.text, password.text)) {
                visible = false

                window.width = _MAIN_WIDTH
                window.height = _MAIN_HEIGHT

                window.maximumWidth = _MAIN_WIDTH
                window.maximumHeight = _MAIN_HEIGHT
                window.minimumWidth = _MAIN_WIDTH
                window.minimumHeight = _MAIN_HEIGHT

                x: Screen.width / 2 - _MAIN_WIDTH / 2
                y: Screen.height / 2 - _MAIN_HEIGHT / 2
            }
        }
    }
}
