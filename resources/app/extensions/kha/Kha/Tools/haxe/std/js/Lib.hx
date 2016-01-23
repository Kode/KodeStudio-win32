/*
 * Copyright (C)2005-2012 Haxe Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
package js;

class Lib {

	/**
		Inserts a 'debugger' statement that will make a breakpoint if a debugger is available.
	**/
	public static inline function debug() {
		untyped __js__("debugger");
	}

	/**
		Display an alert message box containing the given message.
		@deprecated Use Browser.alert() instead.
	**/
	@:deprecated("Lib.alert() is deprecated, use Browser.alert() instead")
	public static function alert( v : Dynamic ) {
		untyped __js__("alert")(js.Boot.__string_rec(v,""));
	}

	public static inline function eval( code : String ) : Dynamic {
		return untyped __js__("eval")(code);
	}

	/**
		Inserts a `require` expression that loads JavaScript object from
		a module or file specified in the `module` argument.

		This is only supported in environments where `require` function
		is available, such as Node.js or RequireJS.
	**/
	public static inline function require( module:String ) : Dynamic {
		return untyped __js__("require")(module);
	}

	/**
		Returns JavaScript `undefined` value.

		Note that this is only needed in very rare cases when working with external JavaScript code.

		In Haxe, `null` is used to represent the absence of a value.
	**/
	public static var undefined(get,never) : Dynamic;
	static inline function get_undefined() : Dynamic {
		return untyped __js__("undefined");
	}

	/**
		`nativeThis` is the JavaScript `this`, which is semantically different
		from the Haxe `this`. Use `nativeThis` only when working with external
		JavaScript code.

		In Haxe, `this` is always bound to a class instance.
		In JavaScript, `this` in a function can be bound to an arbitrary
		variable when the function is called using `func.call(thisObj, ...)` or
		`func.apply(thisObj, [...])`.

		Read more at https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this
	**/
	public static var nativeThis(get,never) : Dynamic;
	@:extern static inline function get_nativeThis() : Dynamic {
		return untyped __js__("this");
	}
}
