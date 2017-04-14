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

    ColumnLayout
    {

        RowLayout
        {
            id: userRowTen
            Text{
                text:"User #10"
            }

            TextField
            {
                id: idTexNameField
                width: 100
                onTextChanged: idTenSetNameButton.enabled = true
            }

            Button{
                id: idTenSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrTen.setUserName(idTexNameField.text);
                    enabled = false;
                    idTexNameField.focus = false;
                }
            }

            Rectangle{
                id: idTen
                height: 20
                width: height
                color: usrTen.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idTenText
                    text: usrTen.counter
                }
            }
        }
        RowLayout
        {
            id: userRowOne
            Text{
                text:"User #1"
            }

            TextField
            {
                id: idOneNameField
                width: 100
                onTextChanged: idOneSetNameButton.enabled = true
            }

            Button{
                id: idOneSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrOne.setUserName(idOneNameField.text);
                    enabled = false;
                    idOneNameField.focus = false;
                }
            }

            Rectangle{
                id: idOne
                height: 20
                width: height
                color: usrOne.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idOneText
                    text: usrOne.counter
                }
            }
        }
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
