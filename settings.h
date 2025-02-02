/**
 * \file settings.h
 *
 * \section LICENSE
 *
 * Copyright (C) 2012-2019 Thorsten Roth <elthoro@gmx.de>
 *
 * This file is part of iQPuzzle.
 *
 * iQPuzzle is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * iQPuzzle is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with iQPuzzle.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \section DESCRIPTION
 * Class definition for settings.
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <QDialog>
#include <QSettings>

namespace Ui {
class SettingsDialog;
}

/**
 * \class Settings
 * \brief Settings dialog.
 */
class Settings : public QDialog {
  Q_OBJECT

 public:
    explicit Settings(const QString &sSharePath, QWidget *pParent = nullptr);
    virtual ~Settings();

    QList<quint8> getMouseControls() const;
    quint8 getShift() const;
    QString getLanguage();

    uint getEasy() const;
    uint getHard() const;

 signals:
    void changeLang(const QString &sLang);

 public slots:
    void accept();
    void reject();
    void updateUiLang();

 private:
    void readSettings();
    QStringList searchTranslations();

    QWidget *m_pParent;
    Ui::SettingsDialog *m_pUi;
    QSettings *m_pSettings;

    QString m_sGuiLanguage;
    const QString m_sSharePath;
    const quint8 m_nSHIFT;
    QStringList m_sListMouseButtons;
    QList<quint8> m_listMouseButtons;
    QList<quint8> m_listMouseControls;
    uint m_nEasy;
    uint m_nHard;
};

#endif  // SETTINGS_H_
