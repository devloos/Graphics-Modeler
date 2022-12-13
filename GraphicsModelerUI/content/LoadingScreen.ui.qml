import QtQuick 2.0

Rectangle {
    z: window._WINDOW_TOP_LEVEL_Z

    width: window._LOGIN_WIDTH
    height: window._LOGIN_HEIGHT

    color: "black"

    Timer {
        interval: 2000; running: true; repeat: false
        onTriggered: {
            main_loading.visible = false
        }
    }

    AnimatedImage { 
        id: animation 
        x: window._LOGIN_WIDTH / 2 - 70
        y: window._LOGIN_HEIGHT / 2 - 70
        width: 140
        height: 140
        source: "spinning-donut.gif" 
    }
}