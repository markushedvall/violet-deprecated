#!/usr/bin/env python

from conans.client.conan_api import Conan

if __name__ == "__main__":
    user = "markushedvall"
    channel = "testing"
    conan, _, _ = Conan.factory()
    conan.create(".", user=user, channel=channel)
