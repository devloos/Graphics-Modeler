import QtQuick 6.4
import QtQuick.Window 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3
import QtQuick.Dialogs 6.4
import My.Singletons
import My.Shapes

Window {
    readonly property int _LOGIN_WIDTH: 640
    readonly property int _LOGIN_HEIGHT: 480

    readonly property int _MAIN_WIDTH: 1080
    readonly property int _MAIN_HEIGHT: 720

    property var dynamicTypes: []
    property var shapeIds: [line, polyline, polygon, rectangle, square, ellipse, circle, text]

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

        id: parent_contact_us
        x: 0
        y: 0
        width: 0
        height: 0
        dim: true
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        ContactPopup {
            id: contact_us_popup

            function open(width, height) {
                contact_us_popup.x = width / 2 - contact_us_popup._CONTACT_WIDTH / 2
                contact_us_popup.y = height / 2 - contact_us_popup._CONTACT_HEIGHT / 2 
                parent_contact_us.open()
            }

            back_btn.onClicked: parent_contact_us.close()
        }
    }

    Popup {
        Material.theme: Material.Light
        Material.accent: Material.Purple

        id: parent_meet_the_team
        x: 0
        y: 0
        width: 0
        height: 0
        dim: true
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        MeetTheTeamPopup {
            id: meet_the_team_popup
            meet_the_team_back_btn.onClicked: parent_meet_the_team.close()
        }
    }

    LoginUI {
        id: login_ui
        visible: true

        login_btn.onClicked: window.validate(username.text, password.text)
        contact_btn.onClicked: contact_us_popup.open(window._LOGIN_WIDTH, window._LOGIN_HEIGHT)
    }

    MainUI {
        id: main_ui
        visible: false

        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            nameFilters: [ "DB files (*.db)" ]
            onAccepted: {
                CppInterface.openFile(fileDialog.currentFile);
                left_side_bar.loadShape(shape_selector.currentIndex - 1);
                fileDialog.close()
            }

            onRejected: {
                fileDialog.close();
            }
        }

        ShapeSelector {
            id: left_side_bar

            GMComboBox {
                id: shape_selector
            }

            function loadShape(index) {
                if (index < 0 || index > 7) {
                    return;
                }

                // reseting component
                loader.sourceComponent = undefined;

                main_ui.renderProperties(index);
                loader.sourceComponent = shapeIds[index];
            }
        }

        GMMenuBar {
            id: menu_bar

            function runReport() {
                CppInterface.runReport();
            }
        }

        ScrollView {
            anchors {
                top: menu_bar.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            Component { id: line; GMLine { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: polyline; GMPolyline { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: polygon; GMPolygon { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: rectangle; GMRectangle { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: square; GMSquare { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: ellipse; GMEllipse { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: circle; GMCircle { x: 40; y: 110; width: 1000; height: 500; } }
            Component { id: text; GMText { x: 40; y: 110; width: 1000; height: 500; } }
        }

        Loader {
            id: loader
            sourceComponent: undefined
        }

        ShapePropertiesPane {
            id: shape_properties_pane
        }

        function clearProperties() {
            dynamicTypes.forEach((type) => {
                type.destroy(0);
            });

            dynamicTypes = [];
        }

        function renderProperties(index) {
            main_ui.clearProperties();

            const properties = CppInterface.getProperties(index);

            let y = 50;
            properties.forEach((property) => {
                const type = Qt.createQmlObject(`
                    import QtQuick 6.4

                    Text {
                        x: 10
                        y: ${y}
                        width: 265
                        height: 25
                        color: '#ffffff'
                        text: '${property}'
                        font.pixelSize: 15
                        font.family: 'Arial'
                        font.bold: true
                    }
                    `,
                    shape_properties_pane,
                );

                dynamicTypes.push(type);
                y += 25;
            });
        }
    }
}
