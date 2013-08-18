// ck2launcher - A Qt5 launcher for Crusader Kings 2 game.
// Copyright (C) 2013  Eduardo Barreto Alexandre

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

#include "gui/configuration.hpp"

#include <QtWidgets/QFileDialog>

#include "configmanager.hpp"

namespace Gui
{
  ////// PUBLIC METHODS //////

  Configuration::Configuration(QWidget * const parent) : QDialog{parent}
  {
    ui_.setupUi(this);

    auto & configManager = ConfigManager::singleton();

    ui_.gamePath_->setText(configManager.gamePath().c_str());
    ui_.configPath_->setText(configManager.configPath().c_str());

    ui_.bumblebeeCommand_->setEnabled(false);
    ui_.bumblebeeCommand_->setCurrentIndex(ui_.bumblebeeCommand_->findText(configManager.bumblebeeCommand().c_str()));

    connect(ui_.bumblebeeEnabled_, &QCheckBox::stateChanged, ui_.bumblebeeCommand_, &QComboBox::setEnabled);
    ui_.bumblebeeEnabled_->setCheckState(configManager.bumblebee() ? Qt::Checked : Qt::Unchecked);

    connect(ui_.buttonBox_, &QDialogButtonBox::accepted, [&]
            {
              configManager.gamePath(ui_.gamePath_->text().toStdString());
              configManager.configPath(ui_.configPath_->text().toStdString());
              
              configManager.bumblebee(ui_.bumblebeeEnabled_->checkState() ? true : false);
              if (ui_.bumblebeeEnabled_->checkState())
                configManager.bumblebeeCommand(ui_.bumblebeeCommand_->currentText().toStdString());
            });

    connect(ui_.openGamePath_, &QPushButton::clicked, [&]
            {
              const auto path = QFileDialog::getExistingDirectory(this, "Open Crusader Kings 2 Game Directory",
                                                                  configManager.gamePath().c_str()).toStdString();

              if (path == "")
                return;

              ui_.gamePath_->setText(path.c_str());
              configManager.gamePath(path);
            });

    connect(ui_.openConfigPath_, &QPushButton::clicked, [&]
            {
              const auto path = QFileDialog::getExistingDirectory(this, "Open Crusader Kings 2 Config Directory",
                                                                  configManager.configPath().c_str()).toStdString();

              if (path == "")
                return;

              ui_.configPath_->setText(path.c_str());
              configManager.configPath(path);
            });
  }
}
