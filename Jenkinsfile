pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Checking out repository...'
                checkout scm
            }
        }

        stage('Restore NuGet') {
            steps {
                echo 'Restoring NuGet packages...'
                bat '"C:\\Program Files\\NuGet\\nuget.exe" restore test_repos.sln'
            }
        }

        stage('Build') {
            steps {
                echo 'Building solution with MSBuild...'
                bat "\"${tool 'MSBuild_17'}\" test_repos.sln /p:Configuration=Debug /p:Platform=x64"
            }
        }

        stage('Run Tests') {
            steps {
                bat 'x64\\Debug\\test_repos.exe --gtest_output="xml:test_report.xml"'
            }
        }

        stage('Test Report') {
            steps {
                xunit {
                    googleTest(pattern: 'test_report.xml')
                }
            }
        }

    }
}
