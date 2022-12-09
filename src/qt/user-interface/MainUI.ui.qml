import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Controls.Material 2.3
import My.Shapes

Rectangle {
    property alias login_test_btn : login_test_btn

    width: window._MAIN_WIDTH
    height: window._MAIN_HEIGHT

    color: "#c2c2c2"

    Ellipse {
        id: ellipse
        width: 400
        height: 400
    }

    Button {
        id: login_test_btn
        x: 79
        y: 276
        z: 0
        width: 162
        height: 48
        text: qsTr("render")
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

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:9}D{i:13}
}
##^##*/
