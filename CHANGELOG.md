# Matrice Change Log

All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

## Change Log Categories

* `[BUG FIX]` Bugs or regressions have been resolved.
* `[FEATURE]` Functionality has been added or improved.
* `[REMOVED]` Functionality has been removed.
* `[QUALITY]` Nonfunctional quality changes to infrastructure, code appearance, etc.

Change Log entries must follow the format:

* `[LABEL]` Description of changes. [Resolves #issue].

### Unreleased Changes

These issues have been fully implemented and merged into develop.

* `[LABEL]` Description of changes. [Resolves #issue].

* `[FEATURE]` Added MatrixStorage class between MatrixBase and outer API classes (Matrix, Vector, etc.) to reduce template flash usage and allow for external storage. Added Matrice_Test_App with acceptance tests for mathematical operator overloads. [Resolves #1].
