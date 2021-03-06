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



#ifndef video_vimeo_H
#define video_vimeo_H

#include <qglobal.h>
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>
#else
#include <QtWebKitWidgets/QtWebKitWidgets>
#endif
#include "video.h"
#include "ui_login_dialog.h"

class video_vimeo : public video
{
    Q_OBJECT

public:
    video_vimeo();
    video* createNewInstance();

    bool setUrl(QString);
    virtual void parseVideo(QString html);

    private:
    QString downloading;
    QDialog* passwordDialog;
    Ui::LoginDialog* dui;

    public slots:
        void handleLogin(QUrl);
        void verifyForm(bool);
};

#endif // video_vimeo_H
