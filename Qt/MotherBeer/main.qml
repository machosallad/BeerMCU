import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

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
        text: udpAnnouncer.isBroadcasting ? "Stop UDP server" : "Start UDP server"
        anchors.centerIn: parent
        onClicked: udpAnnouncer.startBroadcasting()
    }

    statusBar: StatusBar
    {
        Text {
            id: name
            text: udpAnnouncer.isBroadcasting ? "UDP Running" : "UDP Not running"
        }
    }

}
