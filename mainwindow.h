/*
    ClipGrab³
    Copyright (C) Philipp Schmieder
    http://clipgrab.de
    feedback [at] clipgrab [dot] de

    This file is part of ClipGrab.
    ClipGrab is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    ClipGrab is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ClipGrab.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSignalMapper>
#include <QtXml>
#include <QUrl>
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QMainWindow>
#else
#include <QtWidgets/QMainWindow>
#endif
#include "ui_mainwindow.h"
#include "ui_metadata-dialog.h"
#include "clipgrab.h"
#include "notifications.h"

#ifdef Q_WS_MAC64
#include "savedialog_mac.h"
#endif


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
#else
    MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
#endif
    ~MainWindow();
    void init();

    ClipGrab *cg;

public slots:
    void startDownload();
    void compatiblePortalFound(bool, video*);
    void compatibleUrlFoundInClipBoard(QString url);
    void updateVideoInfo();
    void targetFileSelected(QString target);

    //void openFinishedVideo(QModelIndex);

signals:
    void itemToRemove(int);

private:
    Ui::MainWindowClass ui;
     QSignalMapper *changeTabMapper;
     QSignalMapper *downloadMapper;
     video* currentVideo;
     Ui::MetadataDialog mdui;
     QDialog* metadataDialog;
     QSystemTrayIcon systemTrayIcon;
     void disableDownloadUi(bool disable=true);
     void disableDownloadTreeButtons(bool disable=true);
     void closeEvent(QCloseEvent* event);
     void timerEvent(QTimerEvent*);
     void changeEvent(QEvent *);
     QNetworkAccessManager* searchNam;
     QNetworkReply* searchReply;
     void dragEnterEvent(QDragEnterEvent *event);
     void dropEvent(QDropEvent *event);
     bool updatingComboQuality;

private slots:
    void on_mainTab_currentChanged(int index);
    void on_downloadComboFormat_currentIndexChanged(int index);
    void on_searchWebView_linkClicked(QUrl );
    void on_searchLineEdit_textChanged(QString );
    void on_settingsUseMetadata_stateChanged(int );
    void on_label_linkActivated(QString link);
    void on_downloadLineEdit_returnPressed();
    void on_settingsMinimizeToTray_stateChanged(int );
    void on_downloadPause_clicked();
    void on_settingsRemoveFinishedDownloads_stateChanged(int );
    void on_downloadTree_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    void systemTrayMessageClicked();
    void systemTrayIconActivated(QSystemTrayIcon::ActivationReason);
    void on_downloadOpen_clicked();
    void on_settingsSaveLastPath_stateChanged(int );
    void on_downloadCancel_clicked();
    void on_settingsBrowseTargetPath_clicked();
    void on_settingsSavedPath_textChanged(QString );
    void on_settingsNeverAskForPath_stateChanged(int);

    void settingsClipboard_toggled(bool);
    void settingsNotifications_toggled(bool);
    void settingsProxyChanged();
    void processSearchReply();

    void handleFinishedConversion(video*);
    void on_downloadTree_doubleClicked(const QModelIndex);
    void on_settingsLanguage_currentIndexChanged(int index);
    void on_buttonDonate_clicked();
    void on_settingsUseWebM_toggled(bool checked);
    void on_settingsIgnoreSSLErrors_toggled(bool checked);
    void on_downloadTree_customContextMenuRequested(const QPoint &pos);
    void on_settingsRememberLogins_toggled(bool checked);
    void on_settingsRememberVideoQuality_toggled(bool checked);
    void on_downloadComboQuality_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
