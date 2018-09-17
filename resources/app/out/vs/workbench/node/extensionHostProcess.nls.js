/*!--------------------------------------------------------
 * Copyright (C) Microsoft Corporation. All rights reserved.
 *--------------------------------------------------------*/
/*---------------------------------------------------------
 * Copyright (c) Microsoft Corporation. All rights reserved.
 *--------------------------------------------------------*/
define("vs/workbench/node/extensionHostProcess.nls", {
	"vs/base/common/errorMessage": [
		"{0}: {1}",
		"An unknown error occurred. Please consult the log for more details.",
		"A system error occurred ({0})",
		"An unknown error occurred. Please consult the log for more details.",
		"{0} ({1} errors in total)",
		"An unknown error occurred. Please consult the log for more details."
	],
	"vs/base/common/severity": [
		"Error",
		"Warning",
		"Info"
	],
	"vs/editor/common/config/editorOptions": [
		"The editor is not accessible at this time. Press Alt+F1 for options.",
		"Editor content"
	],
	"vs/platform/configuration/common/configurationRegistry": [
		"Default Configuration Overrides",
		"Configure editor settings to be overridden for {0} language.",
		"Configure editor settings to be overridden for a language.",
		"Cannot register '{0}'. This matches property pattern '\\\\[.*\\\\]$' for describing language specific editor settings. Use 'configurationDefaults' contribution.",
		"Cannot register '{0}'. This property is already registered."
	],
	"vs/platform/extensionManagement/common/extensionManagement": [
		"Extensions",
		"Preferences"
	],
	"vs/platform/markers/common/markers": [
		"Error",
		"Warning",
		"Info"
	],
	"vs/platform/workspaces/common/workspaces": [
		"Code Workspace"
	],
	"vs/workbench/api/node/extHost.api.impl": [
		"Extension Host"
	],
	"vs/workbench/api/node/extHostDebugService": [
		"debuggee"
	],
	"vs/workbench/api/node/extHostDiagnostics": [
		"Not showing {0} further errors and warnings."
	],
	"vs/workbench/api/node/extHostExtensionActivator": [
		"Extension '{1}' failed to activate. Reason: unknown dependency '{0}'.",
		"Extension '{1}' failed to activate. Reason: dependency '{0}' failed to activate.",
		"Extension '{0}' failed to activate. Reason: more than 10 levels of dependencies (most likely a dependency loop).",
		"Activating extension '{0}' failed: {1}."
	],
	"vs/workbench/api/node/extHostProgress": [
		"{0} (Extension)"
	],
	"vs/workbench/api/node/extHostTask": [
		"{0}: {1}"
	],
	"vs/workbench/api/node/extHostTreeViews": [
		"No tree view with id '{0}' registered.",
		"No tree view with id '{0}' registered.",
		"No tree view with id '{0}' registered.",
		"No tree view with id '{0}' registered.",
		"Element with id {0} is already registered"
	],
	"vs/workbench/api/node/extHostWorkspace": [
		"Extension '{0}' failed to update workspace folders: {1}"
	],
	"vs/workbench/node/extensionHostMain": [
		"Path {0} does not point to a valid extension test runner."
	],
	"vs/workbench/parts/debug/node/debugAdapter": [
		"Debug adapter executable '{0}' does not exist.",
		"Cannot determine executable for debug adapter '{0}'.",
		"Unable to launch debug adapter from '{0}'.",
		"Unable to launch debug adapter."
	],
	"vs/workbench/parts/debug/node/terminals": [
		"VS Code Console",
		"Script '{0}' failed with exit code {1}",
		"'{0}' not supported",
		"Press any key to continue...",
		"'{0}' failed with exit code {1}"
	],
	"vs/workbench/services/configurationResolver/node/variableResolver": [
		"'{0}' can not be resolved because no environment variable name is given.",
		"'{0}' can not be resolved because setting '{1}' not found.",
		"'{0}' can not be resolved because '{1}' is a structured value.",
		"'{0}' can not be resolved because no settings name is given.",
		"'{0}' can not be resolved because the command has no value.",
		"'{0}' can not be resolved. No such folder '{1}'.",
		"'{0}' can not be resolved in a multi folder workspace. Scope this variable using ':' and a workspace folder name.",
		"'{0}' can not be resolved. Please open a folder.",
		"'{0}' can not be resolved. Please open an editor.",
		"'{0}' can not be resolved. Make sure to have a line selected in the active editor.",
		"'{0}' can not be resolved. Make sure to have some text selected in the active editor."
	]
});