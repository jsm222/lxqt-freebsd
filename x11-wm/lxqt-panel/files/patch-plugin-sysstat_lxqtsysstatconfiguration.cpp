--- plugin-sysstat/lxqtsysstatconfiguration.cpp.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstatconfiguration.cpp
@@ -105,6 +105,7 @@ LXQtSysStatConfiguration::LXQtSysStatCon
     connect(ui->linesSB, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &LXQtSysStatConfiguration::saveSettings);
     connect(ui->titleLE, &QLineEdit::editingFinished, this, &LXQtSysStatConfiguration::saveSettings);
     connect(ui->useFrequencyCB, &QCheckBox::toggled, this, &LXQtSysStatConfiguration::saveSettings);
+    connect(ui->maximumHS, &QSlider::valueChanged, this, &LXQtSysStatConfiguration::saveSettings);
     connect(ui->logarithmicCB, &QCheckBox::toggled, this, &LXQtSysStatConfiguration::saveSettings);
     connect(ui->sourceCOB, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &LXQtSysStatConfiguration::saveSettings);
     connect(ui->useThemeColoursRB, &QRadioButton::toggled, this, &LXQtSysStatConfiguration::saveSettings);
