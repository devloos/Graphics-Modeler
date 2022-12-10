import QtQuick 6.4
import QtQuick.Window 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3
import My.Singletons
import My.Shapes

Window {
    readonly property int _LOGIN_WIDTH: 640
    readonly property int _LOGIN_HEIGHT: 480

    readonly property int _MAIN_WIDTH: 1080
    readonly property int _MAIN_HEIGHT: 720

    readonly property int _WINDOW_TOP_LEVEL_Z: 100

    id: window
    title: "Graphics Modeler"

    width: _LOGIN_WIDTH
    height: _LOGIN_HEIGHT
    maximumWidth: _LOGIN_WIDTH
    maximumHeight: _LOGIN_HEIGHT
    minimumWidth: _LOGIN_WIDTH
    minimumHeight: _LOGIN_HEIGHT

    x: Screen.width / 2 - _LOGIN_WIDTH / 2
    y: Screen.height / 2 - _LOGIN_HEIGHT / 2

    visible: true

    function login() {
        login_ui.visible = false

        window.width = _MAIN_WIDTH
        window.height = _MAIN_HEIGHT

        window.maximumWidth = _MAIN_WIDTH
        window.maximumHeight = _MAIN_HEIGHT
        window.minimumWidth = _MAIN_WIDTH
        window.minimumHeight = _MAIN_HEIGHT

        window.x = Screen.width / 2 - _MAIN_WIDTH / 2
        window.y = Screen.height / 2 - _MAIN_HEIGHT / 2

        main_ui.visible = true
    }

    function logout() {
        main_ui.visible = false

        window.width = _LOGIN_WIDTH
        window.height = _LOGIN_HEIGHT

        window.maximumWidth = _LOGIN_WIDTH
        window.maximumHeight = _LOGIN_HEIGHT
        window.minimumWidth = _LOGIN_WIDTH
        window.minimumHeight = _LOGIN_HEIGHT

        window.x = Screen.width / 2 - _LOGIN_WIDTH / 2
        window.y = Screen.height / 2 - _LOGIN_HEIGHT / 2

        login_ui.visible = true
    }

    function validate(username, password) {
        if (CppInterface.loginConnection(username, password)) {
            window.login()
        }
    }


    Popup {
        Material.theme: Material.Light
        Material.accent: Material.Purple

        id: contact_us_popup
        x: 0
        y: 0
        width: 0
        height: 0
        dim: true
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        ContactPopup {
            back_btn.onClicked: contact_us_popup.close()
        }
    }

    LoginUI {
        id: login_ui
        visible: true

        login_btn.onClicked: window.validate(username.text, password.text)
        contact_btn.onClicked: contact_us_popup.open()
    }

    MainUI {
        id: main_ui
        visible: false
    }
}
