"use strict";
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Microsoft Corporation. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class MoveCursorToPositionCommand {
    constructor() {
        this.id = '_markdown.moveCursorToPosition';
    }
    execute(line, character) {
        if (!vscode.window.activeTextEditor) {
            return;
        }
        const position = new vscode.Position(line, character);
        const selection = new vscode.Selection(position, position);
        vscode.window.activeTextEditor.revealRange(selection);
        vscode.window.activeTextEditor.selection = selection;
    }
}
exports.MoveCursorToPositionCommand = MoveCursorToPositionCommand;
//# sourceMappingURL=https://ticino.blob.core.windows.net/sourcemaps/abd89d197fd1913e759bdec423747c2f1d793e94/extensions\markdown-language-features\out/commands\moveCursorToPosition.js.map
