import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
      width: 135
      z: 2

      color: "#4D4949"
      border.width: 0

      anchors.left: parent.left
      anchors.top: menu_bar.bottom
      anchors.bottom: parent.bottom
      anchors.leftMargin: 0
      anchors.bottomMargin: 0
      anchors.topMargin: 0

      gradient: Gradient {
          GradientStop {
              position: 0
              color: "#646060"
          }

          GradientStop {
              position: 1
              color: "#000000"
          }

          orientation: Gradient.Vertical
      }

      ComboBox {
          id: shape_selector

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

          anchors.left: parent.left
          anchors.right: parent.right
          anchors.top: parent.top
          anchors.rightMargin: 0
          anchors.leftMargin: 0
          anchors.topMargin: 0

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

			main_ui.renderProperties(index - 1);
            switch (index) {
            case 1: {
                loader.sourceComponent = line
                break;
            }

            case 2: {
                loader.sourceComponent = polyline
                break;
            }

            case 3: {
                loader.sourceComponent = polygon
                break;
            }

            case 4: {
                loader.sourceComponent = rectangle
                break;
            }

            case 5: {
                loader.sourceComponent = square
                break;
            }

            case 6: {
                loader.sourceComponent = ellipse
                break;
            }

            case 7: {
                loader.sourceComponent = circle
                break;
            }

            case 8: {
                loader.sourceComponent = text
                break;
            }

            default: {
                loader.sourceComponent = undefined
                break;
            }
            }
          }
      }
  }