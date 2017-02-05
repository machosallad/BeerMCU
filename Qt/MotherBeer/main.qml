import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("MotherBeer")
    width: 300
    height: 200
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button{
        text: backend.isRunnning ? "Stop server" : "Start server"
        anchors.centerIn: parent
        onClicked: backend.startStopServer()
    }

    statusBar: StatusBar
    {
        RowLayout {
            anchors.fill: parent
            Text {
                id: serverRunningText
                text: backend.isRunnning ? "Server Running" : "Server not running"
            }
            Text {
                id: dbText
                text: backend.dbManager.dbPath
            }
        }
    }

}
