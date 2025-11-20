pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Checking out repository...'
                checkout scm
            }
        }

        stage('Restore NuGet Packages') {
            steps {
                echo 'Restoring NuGet packages...'
                bat "nuget restore test_repos.sln"
            }
        }


        stage('Build') {
            steps {
                echo 'Building solution with MSBuild...'
                bat "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe\" \"test_repos.sln\" /p:Configuration=Debug /p:Platform=x64"
            }
        }

        stage('Run Tests') {
            steps {
                echo 'Running Google Tests...'
                bat ".\\x64\\Debug\\test_repos.exe --gtest_output=xml:test_results.xml"
            }
        }

        stage('Test Report') {
            steps {
                echo 'Publishing test results...'
                junit allowEmptyResults: true, testResults: '**/test_results.xml'
            }
        }
    }

    post {
        always {
            echo 'Pipeline finished.'
        }
    }
}
