package flash.text;

extern class TextField extends flash.display.InteractiveObject {
	var alwaysShowSelection : Bool;
	var antiAliasType : AntiAliasType;
	var autoSize : TextFieldAutoSize;
	var background : Bool;
	var backgroundColor : UInt;
	var border : Bool;
	var borderColor : UInt;
	var bottomScrollV(default,never) : Int;
	var caretIndex(default,never) : Int;
	var condenseWhite : Bool;
	var defaultTextFormat : TextFormat;
	var displayAsPassword : Bool;
	var embedFonts : Bool;
	var gridFitType : GridFitType;
	var htmlText : String;
	var length(default,never) : Int;
	var maxChars : Int;
	var maxScrollH(default,never) : Int;
	var maxScrollV(default,never) : Int;
	var mouseWheelEnabled : Bool;
	var multiline : Bool;
	var numLines(default,never) : Int;
	var restrict : String;
	var scrollH : Int;
	var scrollV : Int;
	var selectable : Bool;
	var selectedText(default,never) : String;
	var selectionBeginIndex(default,never) : Int;
	var selectionEndIndex(default,never) : Int;
	var sharpness : Float;
	var styleSheet : StyleSheet;
	var text : String;
	var textColor : UInt;
	var textHeight(default,never) : Float;
	@:require(flash11) var textInteractionMode(default,never) : TextInteractionMode;
	var textWidth(default,never) : Float;
	var thickness : Float;
	var type : TextFieldType;
	var useRichTextClipboard : Bool;
	var wordWrap : Bool;
	function new() : Void;
	function appendText(newText : String) : Void;
	function copyRichText() : String;
	function getCharBoundaries(charIndex : Int) : flash.geom.Rectangle;
	function getCharIndexAtPoint(x : Float, y : Float) : Int;
	function getFirstCharInParagraph(charIndex : Int) : Int;
	function getImageReference(id : String) : flash.display.DisplayObject;
	function getLineIndexAtPoint(x : Float, y : Float) : Int;
	function getLineIndexOfChar(charIndex : Int) : Int;
	function getLineLength(lineIndex : Int) : Int;
	function getLineMetrics(lineIndex : Int) : TextLineMetrics;
	function getLineOffset(lineIndex : Int) : Int;
	function getLineText(lineIndex : Int) : String;
	function getParagraphLength(charIndex : Int) : Int;
	function getRawText() : String;
	function getTextFormat(beginIndex : Int = -1, endIndex : Int = -1) : TextFormat;
	function getTextRuns(beginIndex : Int = 0, endIndex : Int = 2147483647) : Array<Dynamic>;
	function getXMLText(beginIndex : Int = 0, endIndex : Int = 2147483647) : String;
	function insertXMLText(beginIndex : Int, endIndex : Int, richText : String, pasting : Bool = false) : Void;
	function pasteRichText(richText : String) : Bool;
	function replaceSelectedText(value : String) : Void;
	function replaceText(beginIndex : Int, endIndex : Int, newText : String) : Void;
	function setSelection(beginIndex : Int, endIndex : Int) : Void;
	function setTextFormat(format : TextFormat, beginIndex : Int = -1, endIndex : Int = -1) : Void;
	@:require(flash10) static function isFontCompatible(fontName : String, fontStyle : String) : Bool;
}
