import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

ComboBox {
    height: 28
    z: 1
    popup.Material.foreground: "Black"
    Material.accent: "Black"
    Material.foreground: "Black"
    font.bold: true
    popup.font.bold: true

    background: Rectangle {
        color:"grey"
        border.width: parent && parent.activeFocus ? 2 : 1
        border.color: parent && parent.activeFocus ? shape_selector.palette.highlight : shape_selector.palette.button
    }

    model: ["Select", "Line", "Polyline", "Polygon", "Rectangle", "Square", "Ellipse", "Circle", "Text"]

    anchors {
        left: parent.left
        right: parent.right
        top: parent.top
    }

    topInset: 0
    rightPadding: 0
    bottomInset: 0
    wheelEnabled: false
    flat: true
    spacing: 0

    onActivated: (index) => {
        if (index == 0) {
            loader.sourceComponent = undefined
            main_ui.clearProperties();
            return;
        }

        left_side_bar.loadShape(index - 1);
    }
}